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
  Solution(string word, string abbr)
  {
  }

  bool validWordAbb(string word, string abbr)
  {
    int i = 0;
    int j = 0;
    int n = word.size();
    int m = abbr.size();

    while (i < n && j < m)
    {
      if (isdigit(abbr[j]))
      {
        if (abbr[j] == '0')
          return false;
      }

      int num = 0;
      while (j < m && isdigit(abbr[j]))
      {
        num = num * 10 + (abbr[j] - '0');
        j++;
      }

      i += num;
      if (i > n)
        return false;
      else
      {
        if (word[i] != abbr[j])
          return false;
        i++;
        j++;
      }
    }

    return i == n && j == m; // both fully consumed (true)
  }
};

// variant problem
int robotSteps(vector<vector<int>>& grid, int startRow, int startCol)
{
  int numRows = grid.size();
  int numCols = grid[0].size();

  vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));
  visited[startRow][startCol] = true;
  int best = 0;
  dfs(numRows, numCols, 0, startRow, startCol, visited, best, grid);
  return best;

}

void dfs(int numRows, int numCols, int steps, int row, int col, vector<vector<bool>>& vis, int& best, vector<vector<int>>& grid){
   const vector<pair<int,int>> directionals = {{-1, 0}, {1,0}, {0,-1}, {0,1}};

   best = max(best, steps);
   
   for(auto& i : directionals){
     int newR = row + i.first;
     int newC = col + i.second;
     
     if(newR >= 0 && newR < numRows && newC >= 0 && newC < numCols && !vis[newR][newC] && grid[row][col] < grid[newR][newC]){
       vis[newR][newC] = true;
       dfs(numRows, numCols, steps + 1, newR, newC, vis, best, grid);
       vis[newR][newC] = false;
     }

   }
}

    int main()
{

  string word = "apple";
  string abbr = "a2e";
  Solution validWordAbb(word, abbr);
}