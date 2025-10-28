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

/////////////////////////////////////

const reverseString = (s) => {
  const charSArray = [];
  let revString = "";

  // push each character into array
  for (let c of s) {
    charSArray.push(c);
  }

  // pop characters off in reverse
  while (charSArray.length > 0) {
    // in c++ we can use .back()
    revString += charSArray[charSArray.length - 1];
    charSArray.pop();
  }

  return revString;
};

const findMaxinArr = (arr) => {
  let max = [0];

  for (let i = 0; i < arr.length; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
};

const countForVowelsAndConsonants = (s) => {
  let vowels = 0;
  let consonats = 0;

  for (let c of s) {
    c = c.toLowerCase(c);
    if (c >= "a" && c <= "z") {
      if (c == "a" || c == "e" || c == "i" || c == "o" || c == "u") vowels++;
      else consonats++;
    }
  }

  console.log("V", vowels);
  console.log("C", consonats);
};

const arr = [1, 3, 2, 4];
console.log(findMaxinArr(arr));

const string = "hello world";
console.log(reverseString(string)); // "dlrow olleh"

console.log(countForVowelsAndConsonants(string));
