function countBits(n: number): number[] {
    const ans = new Array(n + 1).fill(0);
    for (var x = 1; x <= n; ++x) {
        ans[x] = ans[x & (x-1)] + 1;
    }
    return ans;
};
