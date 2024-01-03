function numberOfBeams(bank: string[]): number {
    let sum = 0;
    let last_row_count = 0;
    for (var i = 0; i < bank.length; i++) {
        const letters = bank[i].split("");
        const count = letters.filter((l) => l == '1').length;
        if (count <= 0) continue;
        sum += last_row_count * count;
        last_row_count = count;
    }
    return sum;
};
