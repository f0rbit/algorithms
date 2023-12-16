// initial solution O(n log n)
function _isAnagram(s: string, t: string): boolean {
    if (s.length != t.length) return false;
    const a_sorted = s.split("").sort();
    const b_sorted = t.split("").sort();
    for (var i = 0; i < s.length; i++) {
        if (a_sorted[i] != b_sorted[i]) return false;
    }
    return true;
};

// improved solution O(n)
function isAnagram(s: string, t: string): boolean {
    if (s.length != t.length) return false;
    const counter = new Array(26).fill(0);
    for (var i = 0; i < s.length; i++) {
        counter[s.charCodeAt(i) - 97]++;
        counter[t.charCodeAt(i) - 97]--;
    }
    return counter.every((c) => c == 0);
}
