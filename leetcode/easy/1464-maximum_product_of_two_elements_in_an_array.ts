function maxProduct(nums: number[]): number {
    let max = 0;
    for (var i = 0; i < nums.length - 1; i++) {
        for (var j = i + 1; j < nums.length; j++) {
            max = Math.max(max, (nums[i] - 1) * (nums[j] - 1));
        }
    }
    return max;
};

// this is a much nicer solution:
function _maxProduct(nums: number[]): number {
    nums.sort((a, b) => b - a);
    return (nums[0] - 1) * (nums[1] - 1)
};
