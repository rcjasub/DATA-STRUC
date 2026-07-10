// 1258
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

class Solution
{
public:
    vector<string> splitIntoWords(string text)
    {
        vector<string> words;
        stringstream ss(text);
        string word;

        while (ss >> word)
        {
            words.push_back(word);
        }

        return words;
    }

    string find(string word, unordered_map<string, string> &parent)
    {

        while (parent[word] != word)
        {
            word = parent[word];
        }

        return word;
    }

    void unionWords(string a, string b, unordered_map<string, string> &parent)
    {
        string parentA = find(a, parent);
        string parentB = find(b, parent);

        if (parentA != parentB)
        {
            parent[parentA] = parentB;
        }
    }

    vector<string> generateSentences(vector<vector<string>> &synonyms, string text)
    {
        unordered_map<string, string> parent;

        // TODO Part 1: initialize + union every synonym pair

        for (int i = 0; i < synonyms.size(); i++)
        {
            string first = synonyms[i][0];
            string second = synonyms[i][1];

            if (parent.find(first) == parent.end())
            {
                parent[first] = first;
            }

            if (parent.find(second) == parent.end())
            {
                parent[second] = second;
            }

            unionWords(first, second, parent);
        }

        // TODO Part 2: group every word by its root, into map<string, vector<string>>
        // (remember to sort each group alphabetically)

        unordered_map<string, vector<string>> groupRoot;
        for (auto &i : parent)
        {
            string word = i.first;
            string root = find(word, parent);
            groupRoot[root].push_back(word);
        }

        for (auto &group : groupRoot)
        {
            sort(group.second.begin(), group.second.end());
        }

        // Part 3 (later): split `text` into words, then backtrack through
        // each word's options to generate every combination.

        vector<string> words = splitIntoWords(text);

        vector<vector<string>> allOptions;
        for (string &word : words)
        {
            vector<string> options;

            if (parent.find(word) != parent.end())
            {
                string root = find(word, parent);
                options = groupRoot[root];
            }
            else
            {
                options = {word};
            }

            allOptions.push_back(options);
        }

        void backtrack(int wordIndex, string currentSentence, vector<vector<string>> &allOptions, vector<string> &result)
        {
            if (wordIndex == allOptions.size())
            {
                result.push_back(currentSentence);
                return;
            }

            for (string &option : allOptions[wordIndex])
            {
                string nextSentence = currentSentence.empty() ? option : currentSentence + " " + option;
                backtrack(wordIndex + 1, nextSentence, allOptions, result);
            }

            void backtrack(int wordIndex, string currentSentence, vector<vector<string>> &allOptions, vector<string> &result)
            {
                if (wordIndex == allOptions.size())
                {
                    result.push_back(currentSentence);
                    return;
                }

                for (string &option : allOptions[wordIndex])
                {
                    string nextSentence = currentSentence.empty() ? option : currentSentence + " " + option;
                    backtrack(wordIndex + 1, nextSentence, allOptions, result);
                }
            }
        }

        vector<string> result;
        return result;
    }
};

int main()
{
    vector<vector<string>> synonyms = {
        {"happy", "joy"}, {"sad", "sorrow"}, {"joy", "cheerful"}};
    string text = "I am happy today but was sad yesterday";

    Solution sol;
    vector<string> result = sol.generateSentences(synonyms, text);

    cout << "Generated " << result.size() << " sentences (should be 6 once Part 3 is done)" << endl;

    return 0;
}


//maybe try some other time