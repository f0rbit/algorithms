function sortPeople(names: string[], heights: number[]): string[] {
    const data = names.map((name, index) => [ name, heights[index] ]) as [string, number][];
    return data.sort((a,b) => b[1] - a[1]).map(([name]) => name);
};
