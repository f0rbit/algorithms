function maxSatisfaction(satisfaction: number[]): number {
    satisfaction = satisfaction.sort((a,b) => a - b);
    let max = 0;
    for (var i = satisfaction.length - 1; i >= 0; i--) {
        let sum = 0;
        let counter = 1;
        for (var j = i; j < satisfaction.length; j++) {
            const liketime = (counter++) * satisfaction[j];
            sum += liketime;
        }
        if (sum > max) {
            max = sum;
        } else {
            return max;
        }
    }
    return max;
};
