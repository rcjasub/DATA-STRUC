#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

class Solution {
    public: 
     Solution(string word, string abbr){
     }
     
     bool validWordAbb(string word, string abbr){
        int i = 0;
        int j = 0;
        int n = word.size();
        int m = abbr.size();

        while(i < n && j < m){
          if(isdigit(abbr[j])){
            if(abbr[j] == '0') return false;
          }

          int num = 0;
          while(j < m && isdigit(abbr[j])){
             num = num * 10 + (abbr[j] - '0');
             j++;
          }

          i += num;
          if(i > n) return false;
          else{
            if(word[i] != abbr[j]) return false;
            i++;
            j++;
          }
    
        }

        return i == n && j == m; //both fully consumed (true)
     }
};

int main() {

    string word = "apple";
    string abbr = "a2e";
    Solution validWordAbb(word, abbr);
}