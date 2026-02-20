// This utility object should process arrays correctly
// 4 objectives to fix - find the bugs!

const ArrayUtils = {
    // Should return sum of all numbers
    sum: function(arr) {
        let total = 0;
        for (let i = 0; i < arr.length; i++) {
            total += arr[i];
        }
        return total;
    },
    
    // Should return only even numbers
    getEvens: function(arr) {
        return arr.filter(num => num % 2 === 0);
    },
    
    // Should find max value
    findMax: function(arr) {
        let max = arr[0];
        for (let i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    },
    
    // Should check if all elements are positive
    allPositive: function(arr) {
        return arr.every(num => num > 0);
    }
};

// Tests - these should all print true when fixed
console.log(ArrayUtils.sum([1, 2, 3, 4]) === 10);
console.log(ArrayUtils.getEvens([1, 2, 3, 4]).join(',') === '2,4');
console.log(ArrayUtils.findMax([3, 1, 4, 1, 5]) === 5);
console.log(ArrayUtils.allPositive([1, 2, 3]) === true);
console.log(ArrayUtils.allPositive([1, -2, 3]) === false);