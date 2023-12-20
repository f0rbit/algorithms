function imageSmoother(img: number[][]): number[][] {
    const n = img.length;
    const m = img[0].length;
    const output = new Array(n).fill(0).map(() => Array(m).fill(0));

    function within(x: number, y: number) {
        return (x >= 0 && x < n) && (y >= 0 && y < m);
    }

    function average(x: number, y: number) {
        let sum = 0;
        let count = 0;
        for (var i = -1; i < 2; i++) {
            for (var j = -1; j < 2; j++) {
                if (within(x + i, y + j)) {
                    sum += img[x+i][y+j];
                    count++;
                }
            }
        }
        return Math.floor(sum / count);
    }

    for (let x = 0; x < n; x++) {
        for (let y = 0; y < m; y++) {
            output[x][y] = average(x, y);
        }
    }

    return output;
};
