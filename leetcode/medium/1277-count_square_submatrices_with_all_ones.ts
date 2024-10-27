function countSquares(matrix: number[][]): number {
    const row = matrix.length;
    const col = matrix[0].length;
    const dp = new Array(row + 1).fill(0).map(() => new Array(col + 1).fill(0))
    let ans = 0;

    for (var i = 0; i < row; i++) {
        for (var j = 0; j < col; j++) {
            if (matrix[i][j] != 1) continue;
            dp[i + 1][j + 1] = Math.min(dp[i][j + 1], dp[i + 1][j], dp[i][j]) + 1;
            ans += dp[i + 1][j + 1];
        }
    }
    return ans;
};
