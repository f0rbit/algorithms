#!/usr/bin/env python3
import json
import urllib.request
import re
import html
import textwrap
import sys

def fetch_problem(slug):
    query = """
    query getQuestionDetail($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        questionId
        title
        difficulty
        content
        codeSnippets { langSlug code }
      }
    }
    """
    
    data = {
        "query": query,
        "variables": {"titleSlug": slug}
    }
    
    req = urllib.request.Request(
        "https://leetcode.com/graphql",
        data=json.dumps(data).encode(),
        headers={
            "Content-Type": "application/json",
            "User-Agent": "Mozilla/5.0",
            "Referer": "https://leetcode.com",
        }
    )
    
    with urllib.request.urlopen(req) as response:
        result = json.loads(response.read().decode())
    
    return result["data"]["question"]

def fetch_random(difficulty):
    query = """
    query randomQuestion($categorySlug: String, $filters: QuestionListFilterInput) {
      randomQuestion(categorySlug: $categorySlug, filters: $filters) {
        titleSlug
      }
    }
    """
    data = {
        "query": query,
        "variables": {"categorySlug": "algorithms", "filters": {"difficulty": difficulty.upper()}}
    }
    req = urllib.request.Request(
        "https://leetcode.com/graphql",
        data=json.dumps(data).encode(),
        headers={
            "Content-Type": "application/json",
            "User-Agent": "Mozilla/5.0",
            "Referer": "https://leetcode.com",
        },
    )
    with urllib.request.urlopen(req) as response:
        result = json.loads(response.read().decode())
    return result["data"]["randomQuestion"]["titleSlug"]

def extract_rust_code(code_snippets):
    for snippet in code_snippets:
        if snippet["langSlug"] == "rust":
            return snippet["code"]
    return None

def clean_html(content):
    # Remove HTML tags
    content = re.sub(r'<[^>]+>', '', content)
    # Unescape HTML entities
    content = html.unescape(content)
    # Clean up whitespace
    content = re.sub(r'\s+', ' ', content).strip()
    return content

def extract_examples(content):
    pre_blocks = re.findall(r'<pre[^>]*>(.*?)</pre>', content, re.DOTALL)
    examples = []
    for block in pre_blocks:
        # Strip HTML tags but preserve newlines
        block = re.sub(r'<[^>]+>', '', block)
        block = html.unescape(block).strip()
        lines = []
        for line in block.split('\n'):
            line = line.strip()
            if line.startswith('Input:') or line.startswith('Output:'):
                lines.append(line)
        if lines:
            examples.append(' | '.join(lines))
    return examples

def extract_description(content):
    # Cut before first example
    content = re.split(r'<p><strong[^>]*>Example', content, maxsplit=1)[0]
    # Also cut before Constraints/Follow-up
    content = re.sub(r'<strong>Constraints:.*', '', content, flags=re.DOTALL | re.IGNORECASE)
    content = re.sub(r'<strong>Follow-up.*', '', content, flags=re.DOTALL | re.IGNORECASE)
    # Replace <p> and <br> with newlines, <li> with bullet points
    content = re.sub(r'<br\s*/?>', '\n', content)
    content = re.sub(r'</p>', '\n', content)
    content = re.sub(r'<li>', '- ', content)
    content = re.sub(r'<[^>]+>', '', content)
    content = html.unescape(content)
    # Clean up multiple blank lines
    content = re.sub(r'\n{3,}', '\n\n', content).strip()
    # Remove non-breaking spaces
    content = content.replace('\xa0', ' ')
    # Wrap and prefix
    result = []
    for line in content.split('\n'):
        line = line.strip()
        if line:
            for wrapped in textwrap.wrap(line, width=76):
                result.append(f'// {wrapped}')
        else:
            result.append('//')
    return '\n'.join(result)

def parse_signature(rust_code):
    """Extract function name, params (with types), return type, and helper definitions."""
    # Split helpers (everything before 'impl Solution') from the signature
    helpers = ''
    if 'impl Solution' in rust_code:
        idx = rust_code.index('impl Solution')
        helpers_raw = rust_code[:idx].strip()
        if helpers_raw:
            # Uncomment helper lines
            helpers = re.sub(r'^// ?', '', helpers_raw, flags=re.MULTILINE)
            lines = []
            for line in helpers.split('\n'):
                stripped = line.strip()
                if stripped and not re.match(r'^(#|pub |impl |fn |struct |enum |type |use |\}|\{)', stripped) and not line.startswith(' '):
                    lines.append(f'// {line}')
                else:
                    lines.append(line)
            helpers = '\n'.join(lines)

    m = re.search(r'pub fn (\w+)\(([^)]*)\)\s*(?:->\s*(.+?))?\s*\{', rust_code)
    if not m:
        return None
    name = m.group(1)
    params_str = m.group(2).strip()
    ret_type = m.group(3).strip() if m.group(3) else ''

    params = []
    if params_str:
        for p in re.split(r',\s*(?![^<>]*>)', params_str):
            parts = p.strip().split(': ', 1)
            if len(parts) == 2:
                params.append((parts[0].strip(), parts[1].strip()))

    return {'name': name, 'params': params, 'ret_type': ret_type, 'helpers': helpers}


def rust_value(val, type_hint):
    """Convert a leetcode example value to Rust syntax based on type hint."""
    val = val.strip()
    if not type_hint:
        return val
    if type_hint == 'bool':
        return val
    if type_hint in ('i32', 'i64', 'u32', 'u64', 'f64', 'usize'):
        return val
    if type_hint == 'String':
        # val is like "abc" — wrap in .to_string()
        return f'{val}.to_string()'
    if type_hint.startswith('Vec<'):
        if val.startswith('[') and val.endswith(']'):
            inner_type = type_hint[4:-1]  # e.g. Vec<i32> -> i32
            inner = val[1:-1]
            if not inner:
                return 'vec![]'
            if inner_type == 'String':
                # ["a","b"] -> vec!["a".to_string(), "b".to_string()]
                items = re.findall(r'"[^"]*"', inner)
                converted = ', '.join(f'{item}.to_string()' for item in items)
                return f'vec![{converted}]'
            if inner_type.startswith('Vec<'):
                # Nested vec like Vec<Vec<i32>> — parse [[1,2],[3,4]]
                sublists = re.findall(r'\[([^\[\]]*)\]', inner)
                converted = ', '.join(f'vec![{s}]' for s in sublists)
                return f'vec![{converted}]'
            return f'vec![{inner}]'
    # Fallback
    return val


def generate_rust_file(question, slug, rust_code):
    question_id = question["questionId"]
    title = question["title"]
    difficulty = question["difficulty"].lower()
    content = question["content"]

    description = extract_description(content)
    examples = extract_examples(content)

    # Parse signature
    sig = parse_signature(rust_code)

    if sig:
        fn_name = sig['name']
        params = sig['params']
        ret_type = sig['ret_type']
        helpers = sig['helpers']

        # Build function signature line
        params_str = ', '.join(f'{name}: {typ}' for name, typ in params)
        ret_str = f' -> {ret_type}' if ret_type else ''
        fn_sig = f'pub fn {fn_name}({params_str}){ret_str}'

        # Build helpers block
        helpers_block = ''
        if helpers:
            helpers_block = helpers.rstrip() + '\n\n'

        # Build test assertions from examples
        test_functions = []
        for i, example in enumerate(examples, 1):
            parts = example.split(' | ')
            assertion = 'todo!("implement test")'
            if len(parts) == 2:
                input_part = parts[0].replace('Input: ', '', 1)
                output_part = parts[1].replace('Output: ', '', 1)
                try:
                    # Parse input args
                    arg_pairs = re.findall(r'(\w+)\s*=\s*(.+?)(?:,\s*(?=\w+\s*=)|$)', input_part)
                    if arg_pairs and len(arg_pairs) == len(params):
                        args = []
                        for (_, raw_val), (_, param_type) in zip(arg_pairs, params):
                            args.append(rust_value(raw_val, param_type))
                        expected = rust_value(output_part, ret_type)
                        call = f'{fn_name}({', '.join(args)})'
                        assertion = f'assert_eq!({call}, {expected});'
                except Exception:
                    assertion = 'todo!("implement test")'

            test_functions.append(f"""    // {example}
    #[test]
    fn test_{i}() {{
        {assertion}
    }}""")

        if not test_functions:
            test_functions = ["""    #[test]
    fn test_1() {
        todo!("implement test")
    }"""]

        tests_section = '\n\n'.join(test_functions)

        # Format rust code as comments for reference
        rust_comments = '\n'.join(f'// {line}' for line in rust_code.split('\n'))

        rust_file = f"""// {question_id}. {title}
// https://leetcode.com/problems/{slug}/
// Difficulty: {difficulty}
// Time: O(?) Space: O(?)
//
{description}

// --- Rust signature ---
{rust_comments}

{helpers_block}{fn_sig} {{
    todo!()
}}

#[cfg(test)]
mod tests {{
    use super::*;

{tests_section}
}}"""
    else:
        # Fallback: couldn't parse signature
        rust_comments = '\n'.join(f'// {line}' for line in rust_code.split('\n'))
        test_functions = []
        for i, example in enumerate(examples, 1):
            test_functions.append(f"""    // {example}
    #[test]
    fn test_{i}() {{
        todo!("implement test")
    }}""")
        tests_section = '\n\n'.join(test_functions) if test_functions else '    #[test]\n    fn test_1() {\n        todo!("implement test")\n    }'

        rust_file = f"""// {question_id}. {title}
// https://leetcode.com/problems/{slug}/
// Difficulty: {difficulty}
// Time: O(?) Space: O(?)
//
{description}

// --- Rust signature ---
{rust_comments}

pub fn solution() {{
    todo!()
}}

#[cfg(test)]
mod tests {{
    use super::*;

{tests_section}
}}"""

    return rust_file, question_id, difficulty

def main():
    if len(sys.argv) < 2:
        print("Usage: python3 .leet_fetch.py <slug>", file=sys.stderr)
        print("       python3 .leet_fetch.py --random <difficulty>", file=sys.stderr)
        sys.exit(1)

    try:
        if sys.argv[1] == "--random":
            if len(sys.argv) != 3:
                print("Usage: python3 .leet_fetch.py --random <easy|medium|hard>", file=sys.stderr)
                sys.exit(1)
            slug = fetch_random(sys.argv[2])
            # Just print the slug and exit — the bash script will call us again with the slug
            print(slug)
            sys.exit(0)

        slug = sys.argv[1]
        question = fetch_problem(slug)
        if not question:
            print(f"Problem '{slug}' not found", file=sys.stderr)
            sys.exit(1)

        rust_code = extract_rust_code(question["codeSnippets"])
        if not rust_code:
            print(f"No Rust snippet found for problem '{slug}'", file=sys.stderr)
            sys.exit(1)

        rust_file, question_id, difficulty = generate_rust_file(question, slug, rust_code)
        print(f"{question_id} {difficulty} {slug}", file=sys.stderr)
        print(rust_file)

    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()