function countFairPairs(nums: number[], lower: number, upper: number): number {
    nums.sort((a,b) => a - b);
    return helper(nums, upper + 1) - helper(nums, lower);
};

function helper(nums: number[], value: number) {
    let left = 0;
    let right = nums.length - 1;
    let result = 0;
    while (left < right) {
        const sum = nums[left] + nums[right];
        if (sum < value) {
            result += (right - left);
            left++;
        } else {
            right--;
        }
    }
    return result;
}
