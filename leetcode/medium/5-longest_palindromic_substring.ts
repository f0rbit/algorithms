// first approach (brute force)

// function longestPalindrome(s: string): string {
//     let highest = s.substring(0, 1);
//     for (var i = 0; i < s.length; i++) {
//         for (var j = i; j <= s.length; j++) {
//             const res = s.substring(i,j);
//             if (!isPalindrome(res)) continue;
//             if (res.length > highest.length) highest = res;

//         }
//     }
//     return highest;
// };

// function isPalindrome(s: string): boolean {
//     return (s.split("").reverse().join("") == s)
// }

// second approach (two pointers)

function expand(s: string, i: number, j: number) {
    let left: number = i;
    let right: number = j;
    while (left >= 0 && right < s.length && (s.charAt(left) == s.charAt(right))) {
        left--;
        right++;
    }
    return right - left - 1;
}

function longestPalindrome(s: string) {
    const ans: { left: number, right: number, length: number } = { left: 0, right: 0, length: 0 };
    for (var i: number = 0; i < s.length; i++) {
        /** @note - have to do 2 different calculations to consider odd & even palindromes differently. */

        const odd_length: number = expand(s,i,i);
        if (odd_length > ans.length) {
            const dist = Math.floor(odd_length / 2);
            ans.left = i - dist;
            ans.right = i + dist;
            ans.length = odd_length;
        }
        const even_length: number = expand(s,i,i+1);
        if (even_length > ans.length) {
            const dist = Math.floor(even_length / 2) - 1;
            ans.left = i - dist;
            ans.right = i + 1 + dist;
            ans.length = even_length;
        }
    }

    return s.substring(ans.left, ans.left + ans.length);
}
