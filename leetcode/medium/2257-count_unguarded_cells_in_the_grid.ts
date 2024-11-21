function countUnguarded(m: number, n: number, guards: number[][], walls: number[][]): number {
    const cells = new Array(m).fill(null).map(() => new Array(n).fill(1));
    walls.forEach((wall) => cells[wall[0]][wall[1]] = -1);
    guards.forEach((g) => cells[g[0]][g[1]] = -2);

    let n_count = (n*m) - walls.length - guards.length;

    guards.forEach((guard) => {
        [-1, 1].forEach((x_dir) => {
            for (let x = guard[1] + x_dir; x >= 0 && x < n; x += x_dir) {
                if (cells[guard[0]][x] < 0) return;
                if (cells[guard[0]][x] == 1) n_count--;
                cells[guard[0]][x] = 0;
            }
        });
        [-1, 1].forEach((y_dir) => {
            for (let y = guard[0] + y_dir; y >= 0 && y < m; y += y_dir) {
                if (cells[y][guard[1]] < 0) return;
                if (cells[y][guard[1]] == 1) n_count--; 
                cells[y][guard[1]] = 0;
            }
        });
    })


    return n_count;
};
