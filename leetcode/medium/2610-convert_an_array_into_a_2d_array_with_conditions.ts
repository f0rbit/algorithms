function findMatrix(nums: number[]): number[][] {
    const seen: Record<number, number> = {};
    const result: number[][] = [];
    
    for (var i = 0; i < nums.length; i++) {
        const num = nums[i];
        if (!seen[num]) seen[num] = 0;
        const idx = seen[num];
        seen[num]++;
        if (!result[idx]) result[idx] = [];
        result[idx].push(num);
    }
    
    return result;
};
