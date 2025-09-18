// to find the max of a subarray
const maxSumSubarray = (s, k) => {
  if (s.length < k) return null; // not enough elements

  let windowSum = 0;

  //start off with the first subarray
  for (let i = 0; i < k; i++) {
    windowSum += s[i];
  }

  // current max
  let max = windowSum;

  //loop through the rest of the array starting of the first subarray
  for (let j = k; j < s.length; j++) {
    // add the new count to the sum based of the new element
    windowSum += s[j];

    //delete the oldest element to have the new count
    windowSum -= s[j - k];

    //check if we need to update max
    max = Math.max(max, windowSum);
  }

  return max;
};

let s = [1, 2, 3, 4, 5];
console.log(maxSumSubarray(s, 3)); // 12 (3+4+5)

/////////////////////////////////////////////////////////////////

const convertToCamalCase = (s) => {
  if (s.length === 0) return "";

  //remove snake case from string, turn into an array
  const parts = s.split(/_+/);

  //put it back together

  const camelCase = parts
    .map((word, index) => {
      // if there  is only one word, first word is always lower case
      if (index === 0) return word.toLowerCase();
      // index != 0: capitalize first letter, lowercase the rest
      return word.charAt(0).toUpperCase() + word.slice(1).toLowerCase();
    })
    //bring it back to a string
    .join("");
  return camelCase;
};

const text = "this__is___a_test";
console.log(convertToCamalCase(text));
