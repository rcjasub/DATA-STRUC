#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <string>
#include <limits.h>
#include <climits>
#include <algorithm>
#include <unordered_set>
#include <algorithm>
using namespace std;

int func(const vector<int> &nums)
{

    int count = 0;

    // for(int i = 0; i < nums.size(); i++){

    //     for(int j = i + 1; j < nums.size(); j++)
    //     {
    //         if(nums[i] == nums[j])
    //         {
    //            count++;
    //         }
    //     }
    // }

    unordered_map<int, int> freq;
    //we store the numbers we seen already, if we see it again it must mean that
    // we are in a higer index number equal to prev index number , so added it to the count
    for (int i : nums)
    {
        if (freq.count(i))
        {
            count += freq[i];
        }

        freq[i]++;
    }

    return count;
}

//check if it is a palidrome
bool validPalidrome(string &s, int left, int right)
{
    while (left < right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool isAlmostPalindrome(string s)
{
    int left = 0;
    int right = s.size() - 1;

    while (left < right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {   // if it fails here again then it is not longer a almost valid pali
            return validPalidrome(s, left++, right) || validPalidrome(s, left, right--);
        }
    }

    return true;
}

int minSubarrayLen(int target, vector<int>& nums)
{
    //check a subarray that is more then or equal to target
    //it must be contiguous
    //find the subarray with the less length

    //we can prop use a window slide, we check with first numbers? move right until it reaches sum or more. 
    //that can ether give us the most or lest length
    //when do we move the other slider? so when is more then target grab its lenght and check for min
    //then move it check if it is more, if it is keep moving left? else move it to the right. 

    int minL = INT_MAX;
    int sum = 0;
    int left = 0;

    for(int right = 0; right < nums.size(); right++)
    {
        sum += nums[right]; // to check if it matches target

        while(sum >= target)
        {
            minL = min(minL, right - left + 1);
            sum -= nums[left]; //is more or the same so move left to try to get a new length
            left++;

        }

    }
    
    return (minL == INT_MIN) ? 0 : minL;

}

vector<int> unique2dArray(vector<vector<int>>& arr)
{
    int r = arr.size();
    int c = arr[0].size();

    unordered_map<int, bool> map;
    vector<int> arrz;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
           if(!map[arr[i][j]])
           {
             arrz.push_back(arr[i][j]);
             map[arr[i][j]] = true;
           }
        }
    }

    return arrz;
}

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    //so we want to sort by start to avoid intervals like [4,7] [1,4]
    //we must check if start is bigger then prev ending point (if not then merge, also if the same)
    //when we merge we must assign the new sub arr and push it into our new 2d array else just push it(if nothing change)
    
    //if empty just return since there is nothing to return
    if(intervals.empty()) return {};

    //sort
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0];
    });

    //lest loop through to compare

    int curr_start = intervals[0][0];
    int curr_end = intervals[0][1];

    vector<vector<int>> merge;

    int size = intervals.size();

    for(int i = 1; i < size; i++)
    {
       int new_start = intervals[i][0];
       int new_end = intervals[i][1];

       //[[1,3],[2,6],[8,10]]...

       // 2 < 3 - true (compare 3 and 6) curr_end = 6
       // curr_start 1, 
       //8 is not bigger then 6 , so then push [1,6]
       //curr becomes [8,10]
       //loop ends so then push the last ones at the end 
       if(new_start <= curr_end)                                  
       {
         curr_end = max(curr_end, new_end);

       } 
       else 
       {
        merge.push_back({curr_start, curr_end});
        curr_start = new_start;
        curr_end = new_end;
       }
    }

    merge.push_back({curr_start, curr_end});
    
    return merge;
    
}
     
vector<int> sumToTarget(vector<int> arr, int target)
{
   // 3 , 4 , 5 , 6 . 2, 1   t = 7

   // 3 numbers to t?

   unordered_map<int, int> map;

   for(int i = 0; i < arr.size(); i++)
   {
        for(int j = i + 1; j < arr.size(); j++)
        {
            int need = target - arr[i] - arr[j];

            if(map.count(need))
            {
                return {i , map[need], j };
            }

            map[arr[j]] = j;
        }
   }

   return {};
}

bool validAnagram(string s , string t)
{
   unordered_map<char , int> myMap;
   
   for(int i : s)
   {
     myMap[i]++;
   }

   for(auto& i : t)
   {
     myMap[i]--;
   }

   for(auto& i : myMap)
   {
     if(i.second != 0 ) return false;
   }

   return true;
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
    }
};


int main()
{
    vector<int> nums = {1, 2, 3, 1, 1, 3};
    int result = func(nums);
    cout << result << endl;
    
    vector<int> rezz = sumToTarget(nums, 7); 
    for(int x : rezz) cout << x << " ";

    cout<<endl;

    string s = "abca";
    bool outC = isAlmostPalindrome(s);
    cout << outC<<endl;

    vector<vector<int>> yo = {{2,3}, {4,2}, {5,7}, {2,4}};
    vector<int> res = unique2dArray(yo);

     for(int x : res) cout << x << " ";
}