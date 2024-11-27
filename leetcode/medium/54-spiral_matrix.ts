type Dir = "n" | "e" | "w" | "s"

function spiralOrder(matrix: number[][]): number[] {
    let dir: Dir = "e";
    let bound = { top: 0, left: 0, bottom: matrix.length - 1, right: matrix[0].length - 1 };
    const n = matrix.length * matrix[0].length;
    const res: number[] = [];
    let x = -1;
    let y = 0;
    while (res.length < n) {
        switch (dir) {
            case 'n':
                y--;
                break;
            case 's':
                y++;
                break;
            case 'w':
                x--;
                break;
            case 'e':
                x++;
                break;
        }

        res.push(matrix[y][x]);

        if (dir == 'e' && x == bound.right) {
            dir = 's';
            bound.top++;
        } else if (dir == 'w' && x == bound.left) {
            dir = 'n';
            bound.bottom--;
        } else if (dir == 's' && y == bound.bottom) {
            dir = 'w';
            bound.right--;
        } else if (dir == 'n' && y == bound.top) {
            dir = 'e';
            bound.left++;
        }
    }

    return res;
};
