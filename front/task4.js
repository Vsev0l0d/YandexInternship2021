const module = {};

function scan(input) {
    const result = {ceil: 0, floor: 0, both: 0};
    if (input.length === 0) return result;
    let floorReached = false;

    function recursion(i, j, direction){
        input[i][j] = 0;

        if (i - 1 >= 0 && input[i - 1][j]) recursion(i - 1, j, direction);
        if (i + 1 < input.length && input[i + 1][j]) recursion(i + 1, j, direction);
        if (j - 1 >= 0 && input[i][j - 1]) recursion(i, j - 1, direction);
        if (j + 1 < input[0].length && input[i][j + 1]) recursion(i, j + 1, direction);

        if (direction && i === input.length - 1 && !floorReached) {
            result.both++;
            floorReached = true;
        }
    }

    for (let j = 0; j < input[0].length; j++, floorReached = false){
        if (input[0][j]) {
            recursion(0, j, 1);
            result.ceil++;
        }
    }
    result.ceil -= result.both;
    for (let j = 0; j < input[0].length; j++){
        if (input[input.length - 1][j]) {
            recursion(0, j, 0);
            result.floor++;
        }
    }
    return result;
}
module.exports = { scan };

console.log(scan([
    [0, 0, 0],
    [1, 0, 1],
    [1, 1, 1]
]));