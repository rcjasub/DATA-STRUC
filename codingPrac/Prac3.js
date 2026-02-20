// String utilities for a web app
// 5 bugs to fix!

const StringProcessor = {
    // Should reverse a string
    reverse: function(str) {
        //splits the word by singular cha, reverse it, join them back next to each other
        return str.split("").reverse().join("");
    },
    
    // Should count vowels (a, e, i, o, u)
    countVowels: function(str) {
        const vowels = 'aeiou';
        let count = 0;
        for (let char of str.toLowerCase()) {
            //does the string vowel have this char(if it does then it means char is part of a vowel)
            if (vowels.includes(char)) {
                count += 1; 
            }
        }
       
        return count;
    },
    
    // Should capitalize first letter of each word
    capitalizeWords: function(str) {
        // split without nothing wraps the whole string, "" single cha, " " means single string/word
        return str.split(' ')
            .map(word => word[0].toUpperCase() + word.slice(1))
            .join(' ');
    },
    
    // Should check if palindrome (ignoring case, spaces)
    isPalindrome: function(str) {
        const cleaned = str.toLowerCase().replace(/\s/g, '');
        return cleaned === cleaned.split('').reverse().join('');
    },
    
    // TODO: Implement truncate - should cut string to max length + "..."
    truncate: function(str, maxLength) {
        if(str.length > maxLength)
        {
            return str.slice(0, maxLength) + '...';
        }

        return str;
    }
};

// Tests
console.log(StringProcessor.reverse('hello') === 'olleh');
console.log(StringProcessor.countVowels('Hello World') === 3);
console.log(StringProcessor.capitalizeWords('hello world') === 'Hello World');
console.log(StringProcessor.isPalindrome('A man a plan a canal Panama') === true);
console.log(StringProcessor.truncate('Hello World', 5) === 'Hello...');