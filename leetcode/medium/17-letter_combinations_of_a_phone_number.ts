const map = {
    '1': [],
    '2': ['a','b','c'],
    '3': ['d','e','f'],
    '4': ['g','h','i'],
    '5': ['j','k','l'],
    '6': ['m','n','o'],
    '7': ['p','r','q','s'],
    '8': ['t','u','v'],
    '9': ['w','x','y','z'],
}

function letterCombinations(digits: string): string[] {
    if (digits.length == 0) return [];
    if (digits.length == 1) return map[digits[0]];

    const first = letterCombinations(digits[0]);
    return first.flatMap((a) => {
        const remaining = letterCombinations(digits.substring(1));
        return remaining.map((b) => a+b);
    });
};

