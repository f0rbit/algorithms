function uniquePathsIII(grid: number[][]): number {
    const cols = grid.length;
    const rows = grid[0].length;
    let path_count = 0;

    function helper(x: number, y: number, remain: number) {
        if (grid[x][y] == 2 && remain == 1) {
            path_count++;
            return;
        }

        const temp = grid[x][y];
        grid[x][y] = -4; // mark as visisted
        remain--;

        const x_dirs = [0,0,1,-1];
        const y_dirs = [1,-1,0,0];
        for (let i = 0; i < 4; i++) {
            const x_val = x + x_dirs[i];
            const y_val = y + y_dirs[i];
            if (x_val < 0 || x_val >= cols) continue;
            if (y_val < 0 || y_val >= rows) continue;
            if (grid[x_val][y_val] == -1) continue;
            if (grid[x_val][y_val] == -4) continue;
            helper(x_val, y_val, remain);
        }
        grid[x][y] = temp; // reset value after completed recursion
    }

    const state = { start_x: -1, start_y: -1, spaces: 0 };
    for (let i = 0; i < cols; i++) {
        for (let j = 0; j < rows; j++) {
            if (grid[i][j] >= 0) {
                state.spaces++;
            }
            if (grid[i][j] == 1) {
                state.start_x = i;
                state.start_y = j;
            }
        }
    }

    helper(state.start_x, state.start_y, state.spaces);

    return path_count;
};
