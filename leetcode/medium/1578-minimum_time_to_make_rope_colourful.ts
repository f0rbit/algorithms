function minCost(s: string, cost: number[]): number {
    let time = 0;
    let i = 0, j = 0;

    while (i < cost.length && j < cost.length) {
        let sum = 0, max = 0;

        while (j < cost.length && s[i] == s[j]) {
            sum += cost[j];
            max = Math.max(max, cost[j]);
            j++;
        }

        time += sum - max;
        i = j;
    }
    return time; 
};
