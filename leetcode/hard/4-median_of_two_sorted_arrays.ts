function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
    const nums = [...nums1, ...nums2].sort((a,b) => a - b);
    if (nums.length == 1) return nums[0];
    const n = nums.length - 2;
    if (n % 2 == 1) return nums[Math.ceil(n / 2)];
    return (nums[Math.floor(n / 2)] + nums[Math.floor(n / 2) + 1]) / 2;
};
