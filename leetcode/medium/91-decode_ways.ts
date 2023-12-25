const memo = new Map<number, number>();

function numDecodings(s: string): number {
    memo.clear();
    return helper(0, s);
};

function helper(index: number, str: string): number {
    if (memo.has(index)) {
        return memo.get(index);
    }

    if (index == str.length) return 1;
    if (str.charAt(index) == '0') return 0;
    if (index == str.length - 1) return 1;

    let ans = helper(index + 1, str);
    if (parseInt(str.substring(index, index + 2)) <= 26) {
        ans += helper(index + 2, str);
    }

    memo.set(index, ans);
    return ans;
}

