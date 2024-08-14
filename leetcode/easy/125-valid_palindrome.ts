function isPalindrome(s: string): boolean {
    const cleanStr = s.split(' ').join('').replace(/[^a-zA-Z0-9]/g, '').toLowerCase()
    const reversed = cleanStr.split('').reverse().join('').toLowerCase()
    return cleanStr === reversed;
};
