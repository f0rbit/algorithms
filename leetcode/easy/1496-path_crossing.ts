const dirs = {
    'N': [0, 1],
    'E': [1, 0],
    'S': [0, -1],
    'W': [-1, 0]
}

function isPathCrossing(path: string): boolean {
    let pos = [0,0];
    const visited = new Set<string>([ "0,0" ]);
    for (let i = 0; i < path.length; i++) {
        const dir = dirs[path.charAt(i)];
        pos[0] += dir[0];
        pos[1] += dir[1];
        const hash = pos[0] + "," + pos[1];
        if (visited.has(hash)) return true;
        visited.add(hash);
    }
    return false;
};
