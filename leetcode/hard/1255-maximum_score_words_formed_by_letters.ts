function maxScoreWords(words: string[], letters: string[], score: number[]): number {
    const values: Record<string, number[]> = {};
    for (const l of letters) {
        if (!values[l]) values[l] = [];
        const s = score[l.charCodeAt(0) - 97];
        values[l].push(s);
    }
    Object.keys(values).forEach((k) => {
        values[k].sort((a,b) => a - b);
    })

    const v = calc_word(words, JSON.parse(JSON.stringify(values)), 0, [], 0);
    return v;
};

function calc_word(words: string[], values: Record<string, number[]>, index: number, used: string[], accum: number): number {
    if (index >= words.length) return accum;
    const og_values = JSON.parse(JSON.stringify(values));

    const sum_function = () => {
        let sum = 0;
        for (const l of words[index]) {
            if (!values[l]) return 0;
            if (values[l].length <= 0) return 0;
            sum += values[l].pop();
        }
        return sum;
    }
    const sum = sum_function();

    const skip_this = calc_word(words, og_values, index + 1, used, accum);
    const use_this = calc_word(words, JSON.parse(JSON.stringify(values)), index + 1, [ ...used, words[index] ], accum + sum)

    return Math.max(skip_this, use_this);
}
