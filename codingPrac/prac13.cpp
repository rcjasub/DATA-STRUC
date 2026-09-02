#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
#include <utility>
#include <set>
#include <queue>
#include <cctype>
using namespace std;

vector<int> sumNeighbors(vector<int> arr)
{
    vector<int> res;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int left = (i - 1 >= 0) ? arr[i - 1] : 0;
        int right = (i + 1 < n) ? arr[i + 1] : 0;
        res.push_back(left + arr[i] + right);
    }

    return res;
}

int longestSubstringWithoutRepeatingChars(string s)
{

    int left = 0, right = 0;
    unordered_set<char> uniq;
    int n = s.length();
    int maxAmnt = 0;

    while (right < n)
    {
        char c = s[right];

        while (uniq.find(c) != uniq.end())
        {
            uniq.erase(s[left]);
            left++;
        }

        uniq.insert(c);
        maxAmnt = max(maxAmnt, right - left + 1);
        right++;
    }
}

void dfs(int row, int col, vector<vector<char>> &grid, set<pair<int, int>> &visited)
{
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
        return;
    if (grid[row][col] == '0' || visited.count({row, col}))
        return;

    visited.insert({row, col});

    dfs(row + 1, col, grid, visited);
    dfs(row - 1, col, grid, visited);
    dfs(row, col + 1, grid, visited);
    dfs(row, col - 1, grid, visited);
}

int numIslands(vector<vector<char>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    set<pair<int, int>> visited;
    int count = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == '1' && !visited.count({i, j}))
            {
                dfs(i, j, grid, visited);
                count++;
            }
        }
    }
    return count;
}

class RandomizedSet {
public:
    set<int> numbers;

    RandomizedSet() {
        // constructor
    }
    
    bool insert(int val) {
       if(numbers.find(val) == numbers.end()){
          numbers.insert(val);
          return true;
       }

       return false;
    }
    
    bool remove(int val) {
        if(numbers.find(val) != numbers.end()){
            numbers.erase(val);
            return true;
        }

         return false;
    }
    
    int getRandom() {
        
    }
};

vector<int> runningSum(vector<int>& nums) {
     vector<int> res;
     int n = nums.size();

     for(int i = 0; i < n; i++){
        int currSum = 0;
        for(int j = 0; j <= i; j++){
            currSum += nums[j];
        }

        res.push_back(currSum);
     } 

     return res;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();
    unordered_map<string, vector<string>> anagrams;
    for(auto& i : strs){
       string key = i;
       sort(key.begin(), key.end());
       anagrams[key].push_back(i);
    }
    
    vector<vector<string>> res;
    for(auto& i : anagrams){
        res.push_back(i.second);
    }

    return res;
}

void rotate(vector<vector<int>>& matrix) {
   int n = matrix.size();
  
   for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++)
        swap(matrix[i][j], matrix[j][i]);
   }

   for(int i = 0; i < n; i++)
   {
      reverse(matrix[i].begin(), matrix[i].end());
   }
}

vector<int> mergeLogs(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();
    vector<int> res;
    int i = 0, j = 0;

    while(i < n && j < m){
        if(a[i] <= b[j]){
            res.push_back(a[i]);
            i++;
        } else {
            res.push_back(b[j]);
            j++;
        }
    }

    while(i < n){
        res.push_back(a[i]);
        i++;
    }

    while(j < m){
        res.push_back(b[j]);
        j++;
    }
    
    return res;

}

vector<vector<int>> imageBlur(vector<vector<int>>& img) {
    int rows = img.size();
    int cols = img[0].size();

    vector<pair<int,int>> dir = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1} };
    vector<vector<int>> res (rows , vector<int> (cols, 0));

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
        {
            int sum = img[i][j];
            int count = 1;

            for(auto& d : dir){
                int newI = i + d.first;
                int newJ = j + d.second;

                if(newI >= 0 && newI < rows && newJ >= 0 && newJ < cols){
                    sum += img[newI][newJ];
                    count++;
                }
            }

            res[i][j] = sum / count;
        }
    }

    return res;
}

class RateLimiter {
public:

    queue<int> tm;
    int N, T;

    RateLimiter(int N, int T) : N(N), T(T) {
        
    }
    
    bool allowRequest(int timestamp) {
        while(!tm.empty() && timestamp - tm.front() >= T){
            tm.pop();
        }

        if((int)tm.size() < N){
            tm.push(timestamp);
            return true;
        }

        return false;
    }
};


int cartTotal(vector<int>& prices, int discount) {
    
    int TotalSum = 0;

    for(int i = 0; i < prices.size(); i++){
        int newPrice = prices[i] * (100 - discount) / 100;
        TotalSum += newPrice;
    }

    return TotalSum;
}

bool isValidPassword(string s) {
    int n = s.length();

    if(n < 8) return false;
     
    bool isUpper = false;
    bool isLower = false;
    bool isDigit = false;
    
    for(int i = 0; i < n; i++){
        char letter = s[i];

        if(isupper(letter))
        {
            isUpper = true;
        }
        else if(islower(letter)){
            
            isLower = true;
        }
        else if(isdigit(letter)){

            isDigit = true;
        }

        if(isUpper && isLower && isDigit) return true;
    }

   return false;
}

bool dfs(int newR, int newC, vector<vector<int>>& warehouse, set<pair<int, int>>& seen){
    if(newR == warehouse.size() - 1 && newC == warehouse[0].size() - 1) return true;
    
    if(newR < 0 || newR >= warehouse.size() || newC < 0 || newC >= warehouse[0].size()) return false;
    
    if(warehouse[newR][newC] == 1) return false;
    if(seen.count({newR, newC})) return false;

     seen.insert({newR, newC});

     if(dfs(newR + 1, newC, warehouse, seen)) return true;
     if(dfs(newR - 1, newC, warehouse, seen)) return true;
     if(dfs(newR, newC + 1, warehouse, seen)) return true;
     if(dfs(newR, newC - 1, warehouse, seen)) return true;
    
     return false;
}

bool canReachExit(vector<vector<int>>& warehouse, int startRow, int startCol) {
    set<pair<int, int>> seen;
     
    if(warehouse[startRow][startCol] == 1) return false;
     
    return dfs(startRow, startCol, warehouse, seen);
}

vector<int> matchOrders(vector<int>& orders, int target) {
    unordered_map<int, int> ord;   // maps value -> index where it was seen
    int n = orders.size();

    for (int i = 0; i < n; i++) {
        int needed = target - orders[i];

        if (ord.find(needed) != ord.end()) {
            return {ord[needed], i};   // found the earlier index that completes the pair
        }

        ord[orders[i]] = i;   // record this value's index for future lookups
    }

    return {};   // no match found (shouldn't happen per problem's guarantee)
}

int maxTempDrop(vector<int>& temps) {
    int maxDrop = 0;
    int n = temps.size();

    for(int i = 1; i < n; i++){

         int drop = 0;
        
        if(temps[i] < temps[i - 1])
        {
            drop = temps[i - 1] - temps[i];
        }

        maxDrop = max(maxDrop, drop);
    }

    return maxDrop;
}

string compressLog(string s) {

     if(s.empty()) return s;

     string res = "";
     int n = s.length();
     int i = 0;

     while(i < n){
        char c = s[i];
        int count = 0;

        while(i < n && c == s[i])
        {
           count++;
           i++;
        }

        res.push_back(c);
        res += to_string(count);
     }

     return (res.length() <= s.length()) ? res : s;
}

int main()
{
    vector<int> a{1, 2, 3, 4};
    vector<int> res = sumNeighbors(a);

    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}