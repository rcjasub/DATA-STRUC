#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string find(string word, unordered_map<string, string>& parent) {
        while (parent[word] != word) {
            word = parent[word];
        }
        return word;
    }

    void unionWords(string a, string b, unordered_map<string, string>& parent) {
        string rootA = find(a, parent);
        string rootB = find(b, parent);
        if (rootA != rootB) {
            parent[rootB] = rootA;
        }
    }

    vector<bool> areSynonyms(vector<vector<string>>& synonyms, vector<vector<string>>& queries) {
        unordered_map<string, string> parent;

        // Part 1: build union-find from synonym pairs (SAME as before)
        for (int i = 0; i < synonyms.size(); i++) {
            string first = synonyms[i][0];
            string second = synonyms[i][1];

            if (parent.find(first) == parent.end()) parent[first] = first;
            if (parent.find(second) == parent.end()) parent[second] = second;

            unionWords(first, second, parent);
        }

        // NEW: instead of grouping + backtracking, just answer each query directly
        vector<bool> results;

        for (int i = 0; i < queries.size(); i++) {
            string q1 = queries[i][0];
            string q2 = queries[i][1];

            bool bothExist = parent.find(q1) != parent.end() && parent.find(q2) != parent.end();

            if (!bothExist) {
                results.push_back(false);  // unseen word can't be synonymous with anything
                continue;
            }

            results.push_back(find(q1, parent) == find(q2, parent));
        }

        return results;
    }
};

int main() {
    vector<vector<string>> synonyms = {
        {"happy","joy"}, {"sad","sorrow"}, {"joy","cheerful"}
    };
    vector<vector<string>> queries = {
        {"happy","cheerful"},  // should be true (transitively connected)
        {"happy","sad"},       // should be false (different groups)
        {"happy","unknown"}    // should be false (unknown never appeared)
    };

    Solution sol;
    vector<bool> results = sol.areSynonyms(synonyms, queries);

    for (int i = 0; i < results.size(); i++) {
        cout << queries[i][0] << " / " << queries[i][1] << " -> " 
             << (results[i] ? "true" : "false") << endl;
    }

    return 0;
}