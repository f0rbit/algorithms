function canJump(nums: number[]): boolean {
    const memo = new Map<number, boolean>();

    function recursive(index: number): boolean {
        if (memo.has(index)) return memo.get(index) ?? false;
        if (index == nums.length - 1) return true;
        let found = false;
        for (var i = nums[index]; i > 0; i--) {
            const target = index + i;
            if (recursive(target)) {
                found = true;
                break;
            }
        }
        memo.set(index, found);
        return found;
    }

    return recursive(0);
};
