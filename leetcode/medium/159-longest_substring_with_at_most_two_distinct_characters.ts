function lengthOfLongestSubstringTwoDistinct(s: string): number {
    if (s.length <= 2) return s.length;

    let left = 0;
    let right = 0;
    const map = new Map<string, number>();

    let max_len = 2;

    while (right < s.length) {  
        map.set(s.charAt(right), right);
        right++;
        
        if (map.size == 3) {
            let del_max = Infinity;
            for (const [key, value] of map) {
                del_max = Math.min(del_max, value);
            }
            map.delete(s.charAt(del_max));
            left = del_max + 1;
        }
        max_len = Math.max(max_len, right - left);
    }
    return max_len;
};
