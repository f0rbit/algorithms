function maxScore(s: string): number {
    const total_ones = s.split("").filter((s) => s == '1').length;
    let max_sum = 0;
    let current_sum = total_ones;
    for (let i = 0; i < s.length - 1; i++) {
        current_sum += s.charAt(i) == '0' ? 1 : -1;
        max_sum = Math.max(max_sum, current_sum);
    }
    return max_sum;
};
