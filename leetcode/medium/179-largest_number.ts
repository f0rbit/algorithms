function largestNumber(nums: number[]): string {
    const strs = nums.map(String).sort((a,b) => (a + b) > (b + a) ? -1 : 1);
    if (strs[0] == "0") return "0";
    return strs.join("");
};