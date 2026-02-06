const twoSum = (vector, target) => {
    if (vector[0] + vector[1] === target) {
        return [0, 1];
    }

    let pair = new Map();

    for (let i = 0; i < vector.length; i++) {
        let sum = target - vector[i];
        console.log("Sum: ", sum);
        console.log("Is pair: ", pair.has(sum));
        if (pair.has(sum)) {
            return [i, pair.get(sum)]
        }

        pair.set(vector[i], i);
    }
    return [];
}


console.log("Two Sum: ", twoSum([-6, 4, 6, 3], -3));
