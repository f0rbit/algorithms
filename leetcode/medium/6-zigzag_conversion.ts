function convert(s: string, numRows: number): string {
    if (numRows == 1) return s;
    const rows = new Array(numRows).fill('');
    let x = -1;
    let dir: "up" | "down" = "down";

    for (let i = 0; i < s.length; i++) {
        x += dir == "down" ? 1 : -1;
        rows[x] += s[i];

        if (x === numRows - 1) {
            dir = "up";
        } else if (x === 0) {
            dir = "down";
        }
    }

    return rows.join('');
};
