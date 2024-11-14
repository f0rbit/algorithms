function minimizedMaximum(n: number, quantities: number[]): number {
    let left = 0;
    let right = Math.max(...quantities);

    while (left < right) {
        const mid = Math.floor((left + right) / 2);
        if (canDistribute(n, quantities, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
};

function canDistribute(n: number, q: number[], x: number): boolean {
    let j = 0;
    let remaining = q[j];

    for (var i = 0; i < n; i++) {
        if (remaining <= x) {
            j++;
            if (j == q.length) return true;
            remaining = q[j];
        } else {
            remaining -= x;
        }
    }

    return false;
}
