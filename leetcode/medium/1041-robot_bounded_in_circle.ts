type Direction = "n" | "s" | "e" | "w";
function isRobotBounded(instructions: string): boolean {
    // try 20 times to find if we ever end up at 0,0 north
    let x = 0;
    let y = 0;
    let dir: Direction = "n";

    for (var i = 0; i < 20; i++) {
        [x,y,dir] = helper(instructions, x, y, dir);
        if (x == 0 && y == 0 && dir == "n") return true;
    }
    return false;
};

function helper(inst: string, x: number, y: number, dir: Direction): [number,number,Direction] {
    // go through characters and modify
    for (var i = 0; i < inst.length; i++) {
        switch (inst[i]) {
            case 'G':
                switch (dir) {
                    case 'n':
                        y++;
                        break;
                    case 's':
                        y--;
                        break;
                    case 'e':
                        x++;
                        break;
                    case 'w':
                        x--;
                        break;
                }
                break;
            case 'L':
                switch (dir) {
                    case 'n':
                        dir = 'w';
                        break;
                    case 's':
                        dir = 'e';
                        break;
                    case 'e':
                        dir = 'n';
                        break;
                    case 'w':
                        dir = 's';
                        break;
                }
                break;
            case 'R':
                switch (dir) {
                    case 'n':
                        dir = 'e';
                        break;
                    case 's':
                        dir = 'w';
                        break;
                    case 'e':
                        dir = 's';
                        break;
                    case 'w':
                        dir = 'n'
                        break;
                }
                break;
        }
    }
    return [x,y,dir];
}
