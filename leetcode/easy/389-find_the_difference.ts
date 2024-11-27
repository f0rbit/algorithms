function findTheDifference(s: string, t: string): string {
    for (var i = 0; i < s.length; i++) {
        // remove s[i] from t
        const idx = t.indexOf(s[i]);
        t = t.substring(0, idx) + t.substring(idx + 1, t.length);
    }
    return t;
};
