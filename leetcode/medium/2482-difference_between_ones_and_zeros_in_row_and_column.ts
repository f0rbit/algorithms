function onesMinusZeros(grid: number[][]): number[][] {
    const m = grid.length;
    const n = grid[0].length;
    const rows = [Array(m).fill(0), Array(m).fill(0)];
    const cols = [Array(n).fill(0), Array(n).fill(0)];
    for (var i = 0; i < m; i++) {
        for (var j = 0; j < n; j++) {
            const x = grid[i][j];
            rows[x][i]++;
            cols[x][j]++;
        }
    }

    for (var i = 0; i < m; i++) {
        for (var j = 0; j < n; j++) {
            grid[i][j] = rows[1][i] + cols[1][j] - rows[0][i] - cols[0][j];
        }
    }
    return grid;
};
