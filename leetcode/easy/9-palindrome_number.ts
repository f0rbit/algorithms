function isPalindrome(x: number): boolean {
    if (x < 0) return false;
    if (x == 0) return true;
    const queue: string[] = [];
    // convert to string
    const y = x + "";
    for (var i = 0; i < y.length / 2; i++) {
        queue.push(y.charAt(i));
    }
    for (var i = y.length / 2; i < y.length; i++) {
        const a = y.charAt(i);
        const b = queue.pop();
        if (a == b) continue;
        return false;
    }

    return true;    
    // after looking at solutions, I would've done:
    // return parseInt(x.toString().split("").reverse().join("")) == x;
};
