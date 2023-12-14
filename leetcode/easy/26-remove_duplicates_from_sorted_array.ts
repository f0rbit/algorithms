function removeDuplicates(nums: number[]): number {
    const seen = new Set();
    for (var i = 0; i < nums.length; i++) {
        if (seen.has(nums[i])) continue;
        nums[seen.size] = nums[i];
        seen.add(nums[i]);
    }
    nums.length = seen.size;
    return seen.size;
};
