function minOperations(s: string): number {
    const changes = s.split("").reduce((acc, ch, i) => {
        if (ch == (i % 2 == 0 ? '1' : '0')) return acc + 1;
        return acc;
    }, 0);
    return Math.min(changes, s.length - changes);
};
