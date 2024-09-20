function productExceptSelf(nums: number[]): number[] {
    const n = nums.length;
    const left_right = new Array(n).fill(1);
    const right_left = new Array(n).fill(1);
    const res = new Array(n).fill(1);

    for (let i = 1; i < n; i++) {
        left_right[i] = left_right[i - 1] * nums[i - 1];
        right_left[n - i - 1] = right_left[n - i] * nums[n - i];
    }

    for (let i = 0; i < n; i++) {
        res[i] = left_right[i] * right_left[i];
    }

    return res;
};
