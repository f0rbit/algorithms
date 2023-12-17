function romanToInt(s: string): number {
    const tokens = {
        'M': 1000,
        'CM': 900,
        'D': 500,
        'CD': 400,
        'C': 100,
        'XC': 90,
        'L': 50,
        'XL': 40,
        'X': 10,
        'IX': 9,
        'V': 5,
        'IV': 4,
        'I': 1
    }

    let sum = 0;
    for (const [token, value] of Object.entries(tokens)) {
        while (s.startsWith(token)) {
            s = s.substring(token.length);
            sum += value;
        }
    }
    return sum;
};
