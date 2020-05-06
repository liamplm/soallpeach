function a(arr) {
    return arr.reduce((sum, x) => sum + x, 0)
}

function b(arr) {
    let sum = 0;
    for (let i = 0; i < arr.length; i++) {
        sum += arr[i];
    }
    return sum;
}

const { readFileSync } = require('fs');

const input = readFileSync(process.argv[2])

const nums = input.toString().split('\n').map((str) => parseInt(str))

console.log(nums)

console.log(process.argv[3] == 'a' ? a(nums) : b(nums))
