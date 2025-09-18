const firstElAppearsMoreThanOnce = (s) => {
  if (s.length === 0) return -1;

  let map = new Map();

  for (let x of s) {
    if (map.has(x)) {
      return x;
    } else {
      map.set(x, true);
    }
  }

  return -1;
};

console.log(firstElAppearsMoreThanOnce([2, 5, 1, 2, 3, 5])); // Output: 2

const lengthOfLongestSubstring = (s) => {
  let set = new Set();
  let left = 0;
  let maxLength = 0;

  for (let right = 0; right < s.length; right++) {
    while (set.has(s[right])) {
      set.delete(s[left]);
      left++;
    }

    set.add(s[right]);
    console.log("Full set: ", [...set]);
    maxLength = Math.max(maxLength, right - left + 1);
  }

  return maxLength;
};

let s = "abca";
console.log(lengthOfLongestSubstring(s));
