function minimumOneBitOperations(n: number): number {
    if (n == 0) return 0;

    var k = 0, curr = 1;
    while (curr * 2 <= n) {
        curr *= 2;
        k++;
    }

    return (1 << (k+1)) - 1 - minimumOneBitOperations(n ^ curr);
};
