/*
Went through a couple different attempts:
1. brute force recursive generate all permuations, perform sum() calc and return max
    (time limit exceeded)
2. go through requests array at start, store occurences in a map, sort map, generate permuation, run sum()
    (time limit exceeded) was incrementing count for each index from r[0] to r[1]
3. instead of looping and incrementing count at each index from r[0] to r[1], increment 1 at start and -1 at end
   then build count array through one loop. no need to build optimal
*/

function maxSumRangeQuery(nums: number[], requests: number[][]): number {
    const n = nums.length;
    const count = new Array(n).fill(0);
    for (const r of requests) {
        count[r[0]] += 1;
        if (r[1] + 1 < n) count[r[1] + 1] -= 1;
    }
    for (var i = 1; i < n; i++) {
        count[i] += count[i - 1];
    }

    nums.sort((a,b) => a - b);
    count.sort((a,b) => a - b);

    let res = 0;

    for (let i = 0; i < n; i++) {
        res += nums[i] * count[i];
    }

    return res % (Math.pow(10, 9)+7);
};
