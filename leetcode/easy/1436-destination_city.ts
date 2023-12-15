function destCity(paths: string[][]): string {
    const from = new Set<string>();
    const to = new Set<string>();
    paths.forEach((path) => {
        from.add(path[0]);
        to.add(path[1]);
    })
    for (const dest of Array.from(to)) {
        if (from.has(dest)) continue;
        return dest;
    }
    throw new Error("Could not find a destination");
};
