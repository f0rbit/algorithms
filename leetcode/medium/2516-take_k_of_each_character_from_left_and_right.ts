const c = { 'a': 0, 'b': 1, 'c': 2 };

function takeCharacters(s: string, k: number): number {
    const count = [0,0,0];

    for (var i = 0; i < s.length; i++) {
        count[c[s.charAt(i)]]++;
    }

    if (count[0] < k || count[1] < k || count[2] < k) return -1; // base case

    let window = [0,0,0];
    let left = 0;
    let max_window = 0;

    for (let right = 0; right < s.length; right++) {
        window[c[s.charAt(right)]]++;

        while (left <= right && (
            count[0] - window[0] < k ||
            count[1] - window[1] < k ||
            count[2] - window[2] < k
        )) {
            window[c[s.charAt(left)]]--;
            left++;
        }

        max_window = Math.max(max_window, right - left + 1);
    }

    return s.length - max_window;
};
