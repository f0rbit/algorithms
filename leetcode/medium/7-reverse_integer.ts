function reverse(x: number): number {
    const val = String(Math.abs(x)).split("").reverse().join("");
    if (Number(val) > Math.pow(2, 31) - 1) return 0;
    if (x < 0) return -1 * Number(val);
    return Number(val);
};
