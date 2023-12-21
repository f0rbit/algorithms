function maxWidthOfVerticalArea(points: number[][]): number {
    const x_values = points.map((p) => p[0]).sort((a,b) => a - b);
    let max_diff = 0;
    for (var i = 0; i < x_values.length - 1; i++) {
        max_diff = Math.max(max_diff, x_values[i + 1] - x_values[i]);
    }
    return max_diff;
};
