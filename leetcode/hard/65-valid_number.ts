const digits = ['1','2','3','4','5','6','7','8','9','0'];

const is_integer = (string: string) => {
    if (string.length == 0) return false;
    if (string.includes(".")) return false;
    if (still_has_sign(string)) return false;
    return is_digits(string);
}

const is_digits = (string: string) => {
    if (string.length == 0) return false;
    return string.split("").every((c) => digits.includes(c));
}

const still_has_sign = (string: string) => {
    if (string.indexOf("-") != -1) return false;
    if (string.indexOf("+") != -1) return false;
}


function isNumber(s: string): boolean {
    // first case is to get rid of the exponent
    s = s.toLowerCase();
    const exp_idx = s.indexOf('e');
    if (exp_idx != -1) {
        const exp_str = s.substring(exp_idx + 1);
        // check to see if the digits following the exponent are valid
        // we allow 1 sign in the first position
        const has_sign = ['-', '+'].includes(exp_str[0]);
        // check to see if start_idx...-1 is valid INTEGER
        // integer = no decimals, no characters
        const int_str = exp_str.substring(has_sign ? 1 : 0);
        if (!is_integer(int_str)) {
            return false;
        }
        s = s.substring(0, exp_idx);
    }

    // we can have sign at the start
    const has_sign = ['-','+'].includes(s[0]);
    s = s.substring(has_sign ? 1 : 0);
    if (still_has_sign(s)) return false;

    const dec_idx = s.indexOf(".");
    if (dec_idx != -1) {
        const p1 = s.substring(0, dec_idx);
        const p2 = s.substring(dec_idx + 1);
        if (p2.length == 0 && p1.length == 0) return false;
        if (p1.length > 0 && !is_integer(p1)) return false;
        if (p2.length > 0 && !is_integer(p2)) return false;
    } else {
        if (!is_integer(s)) return false; 
    }

    return true;
};
