function repeatedSubstringPattern(s: string): boolean {
    for (var i = 1; i <= Math.floor(s.length / 2); i++) {
        if (s.length % i != 0) continue;
        const substr = s.substring(0, i);

        let combined = "";
        for (var j = 0; j < s.length / i; j++) {
            combined += substr;
        }

        if (combined == s) return true;
    }
    return false;
};
