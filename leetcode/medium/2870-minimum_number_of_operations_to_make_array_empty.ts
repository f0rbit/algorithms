const memo = { '2': 1, '3': 1 };

function minOperations(nums: number[]): number {
    const count: Record<number, number> = {};
    for (var i = 0; i < nums.length; i++) {
        const n = nums[i];
        if (!count[n]) count[n] = 0;
        count[n]++;
    }

    const operations = (n: number) => {
        if (memo[n]) return memo[n];
        if (n == 1) return Infinity;
        if (n == 0) return 0;
        if (n < 0) return Infinity;
        let three = operations(n - 3);
        let two = operations(n - 2);
        const result = Math.min(two, three) + 1;
        memo[n] = result;
        return result;
    }

    if (Object.values(count).includes(1)) return -1;
    const result = Object.values(count).reduce((acc, curr) => acc + operations(curr), 0);
    return result;

};
