function majorityElement(nums: number[]): number {
    const count = new Map();
    for (var i = 0; i < nums.length; i++) {
        if (!count.has(nums[i])) count.set(nums[i], 0);
        count.set(nums[i], count.get(nums[i]) + 1);
        if (count.get(nums[i]) > nums.length / 2) return nums[i];
    }
    return 0;
};
