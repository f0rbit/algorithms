function numSpecial(mat: number[][]): number {
    const m = mat.length;
    const n = mat[0].length;

    const row_sum = new Array(m).fill(0);
    const col_sum = new Array(n).fill(0);

    for (let row = 0; row < m; ++row) {
        for (let col = 0; col < n; ++col) {
            if (mat[row][col] != 1) continue;
            row_sum[row]++;
            col_sum[col]++;
        }
    }

    let sum = 0;
    for (let row = 0; row < m; ++row) {
        for (let col = 0; col < n; ++col) {
            if (mat[row][col] != 1) continue;
            if (row_sum[row] == 1 && col_sum[col] == 1) sum++;
        }
    }
    return sum;
};
