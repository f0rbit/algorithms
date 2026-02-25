# LeetCode — Rust

Rust-based leetcode workspace with neotest integration for Neovim. Solutions and tests live in a single file per problem.

## Prerequisites

- [Rust](https://rustup.rs/) (rustc + cargo)
- [cargo-nextest](https://nexte.st/) — `cargo install cargo-nextest`
- [rust-analyzer](https://rust-analyzer.github.io/) — LSP for Rust
- Python 3 (stdlib only, for the `pull`/`random` commands)
- Neovim with [neotest](https://github.com/nvim-neotest/neotest) + [neotest-rust](https://github.com/rouge8/neotest-rust)

## Structure

```
leetcode/
├── Cargo.toml          # [[test]] entry per .rs file
├── leet                # CLI for scaffolding & fetching problems
├── .leet_fetch.py      # LeetCode GraphQL API helper
├── easy/               # Easy problems
├── medium/             # Medium problems
└── hard/               # Hard problems
```

Each `.rs` file is a standalone Cargo test target registered via `[[test]]` in `Cargo.toml`. The solution function and `#[test]` functions coexist in one file. Legacy `.cpp` and `.ts` solutions also live in the difficulty directories.

## CLI — `./leet`

### Pull a problem from LeetCode

```bash
./leet pull two-sum              # auto-detects difficulty
./leet pull two-sum easy         # override difficulty
```

Fetches the problem description, Rust function signature, and example test cases from LeetCode's API. Creates a ready-to-edit `.rs` file with auto-generated `assert_eq!` tests.

### Pull a random unsolved problem

```bash
./leet random easy
./leet random medium
./leet random hard
```

Fetches a random problem you haven't solved yet (checks all existing files across `.rs`, `.cpp`, `.ts`).

### Create a blank problem manually

```bash
./leet new easy 1 two_sum
```

Creates `easy/1-two_sum.rs` with a minimal template.

### Other commands

```bash
./leet list              # List all problem files (all languages)
./leet find 283          # Find a problem by number
./leet sync              # Regenerate Cargo.toml [[test]] entries from .rs files
```

`sync` regenerates all `[[test]]` entries by scanning `.rs` files in `easy/`, `medium/`, `hard/`. The `pull`, `random`, and `new` commands auto-update `Cargo.toml`.

## Workflow

1. **Get a problem**
   ```bash
   ./leet random medium
   # or: ./leet pull longest-substring-without-repeating-characters
   ```

2. **Open the file in Neovim** — rust-analyzer attaches automatically

3. **Read the description** at the top of the file. Check the Rust signature in the `// --- Rust signature ---` block.

4. **Write your test cases** — the examples have auto-generated `assert_eq!` calls. Add your own edge cases.

5. **Run tests**
   - `<leader>tt` — run test under cursor
   - `<leader>tf` — run all tests in file
   - `<leader>to` — show test output
   - `<leader>ts` — toggle test summary panel

6. **Implement the solution** — replace `todo!()`

7. **Fill in complexity** — update `Time: O(?) Space: O(?)`

## File format

A pulled problem looks like:

```rust
// 1. Two Sum
// https://leetcode.com/problems/two-sum/
// Difficulty: easy
// Time: O(?) Space: O(?)
//
// Given an array of integers nums and an integer target...

// --- Rust signature ---
// impl Solution {
//     pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
//     }
// }

pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    todo!()
}

#[cfg(test)]
mod tests {
    use super::*;

    // Input: nums = [2,7,11,15], target = 9 | Output: [0,1]
    #[test]
    fn test_1() {
        assert_eq!(two_sum(vec![2, 7, 11, 15], 9), vec![0, 1]);
    }
}
```

## Running tests from the terminal

```bash
cargo nextest run                                              # run all
cargo nextest run --test e_789_kth_largest_element_in_a_stream  # run one problem
```

## neotest-rust patch

The neotest-rust plugin is patched to support `easy/`, `medium/`, `hard/` directories as test targets (it only supports `tests/` and `src/` by default). The patch is at:

```
~/.local/share/nvim/lazy/neotest-rust/lua/neotest-rust/init.lua
```

If the plugin updates and overwrites the patch, run `./leet sync` and re-apply. The patch adds `easy`, `medium`, `hard` to `custom_test_dirs` and updates `is_integration_test`, `integration_test_name`, and `path_to_test_path`.

## Tips

- **Write tests before the solution.** Forces you to understand the problem.
- **Use `todo!()`** — compiles but panics at runtime. Great for TDD.
- **Tag your solutions** — add `// tags: two-pointer, hash-map` to grep by pattern later.
- **Fill in complexity** — `Time: O(?) Space: O(?)` after solving.