function intToRoman(num: number): string {
    const tokens = {
        "M": 1000,
        "CM": 900,
        "D": 500,
        "CD": 400,
        "C": 100,
        "XC": 90,
        "L": 50,
        "XL": 40,
        "X": 10,
        "IX": 9,
        "V": 5,
        "IV": 4,
        "I": 1 
    };
    let result = "";
    for (const t in tokens) {
        const res = Math.floor(num / tokens[t]);
        if (res > 0) {
            for (var i = 0; i < res; i++) result += t;
            num = num % tokens[t];
        }
    }
    return result;
};

// apparently there is an O(1) solution as follows:
function _intToRoman(num: number): string {
    const I = ["","I","II","III","IV","V","VI","VII","VIII","IX"];
    const X = ["","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"];
    const C = ["","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"];
    const M = ["","M","MM","MMM"];
    return M[Math.floor(num / 1000)]
        + C[Math.floor((num % 1000) / 100)]
        + X[Math.floor((num % 100) / 10)]
        + I[Math.floor(num % 10)];
};
