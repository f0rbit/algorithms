
function minimumTime(grid: number[][]): number {
    if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

    const rows = grid.length;
    const cols = grid[0].length;

    const directions = [ [1,0], [-1,0], [0,1], [0,-1] ];
    const visited = new Array(rows).fill(null).map((_) => new Array(cols));
 
    const pq = new MinPriorityQueue({ priority: x => x[0] });

    pq.enqueue([ grid[0][0], 0, 0 ]);

    while (!pq.isEmpty()) {
        const curr = pq.dequeue().element as any;
        const [time, row, col] = curr;
        if (row == rows - 1 && col == cols - 1) return time;

        if (visited[row][col]) continue;
        visited[row][col] = true;

        for (const d of directions) {
            const next_row = row + d[0];
            const next_col = col + d[1];
            if (!is_valid(visited, next_row, next_col)) continue;

            const next_cost = grid[next_row][next_col];
            const wait_time = ((next_cost - time) % 2 == 0) ? 1 : 0;
            const next_time = Math.max(next_cost + wait_time, time + 1);
            pq.enqueue([ next_time, next_row, next_col]);
        }
    }
    return -1;
};

function is_valid(visited: number[][], row: number, col: number) {
    return (
        row >= 0 &&
        col >= 0 &&
        row < visited.length &&
        col < visited[0].length &&
        !visited[row][col]
    );
}
