// function rangeBitwiseAnd(left: number, right: number): number {
//     var sum = right;
//     for (var i = right; i >= left; i--) {
//         sum = sum & i;
//         if (sum == 0) return 0;
//     }
//     return sum;
// };

function rangeBitwiseAnd(left: number, right: number): number {
    let count = 0;
    while (left != right) {
        left >>= 1;
        right >>= 1;
        count++;
    }

    return left << count;
}
