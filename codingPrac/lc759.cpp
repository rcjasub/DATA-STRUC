#include<vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> employeeFreeTime(vector<vector<vector<int>>>& schedule) {
        vector<vector<int>> intervals;

        // TODO Step 1: flatten every employee's busy intervals into one flat list
        for(int i = 0; i < schedule.size(); i++) {
            for(int j = 0; j < schedule[i].size(); j++)
            {
                intervals.push_back(schedule[i][j]);
            }
        }
        // TODO Step 2: sort intervals by start time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a , const vector<int>&b ) {
           return a[0] < b[0];
        });

        // TODO Step 3: merge overlapping intervals (same as Merge Intervals)

        vector<vector<int>> mergedList;

        int curr_start = intervals[0][0];
        int curr_end = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){

            int new_start = intervals[i][0];
            int new_end = intervals[i][1];
            
            if(new_start < curr_end) {
                curr_end = max(curr_end, new_end);
            }
            else{
                mergedList.push_back({curr_start, curr_end});
                curr_start = new_start;
                curr_end = new_end;
            }
        }

        mergedList.push_back({curr_start, curr_end});

        // TODO Step 4: walk through merged list, find gaps between neighbors
        vector<vector<int>> result;
        
        int merged_end = mergedList[0][1];

        for(int i = 1; i < mergedList.size(); i++) {
            
            int new_merged_start = mergedList[i][0];

            if(new_merged_start > merged_end) {
                result.push_back({merged_end, new_merged_start});
            } 

            merged_end = mergedList[i][1];
        }

        return result;
    }
};

void printIntervals(vector<vector<int>>& intervals) {
    for (auto& interval : intervals) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
}

int main() {
    // employee 1: busy [1,2] and [5,6]
    // employee 2: busy [1,3]
    // employee 3: busy [4,10]
    vector<vector<vector<int>>> schedule = {
        {{1,2}, {5,6}},
        {{1,3}},
        {{4,10}}
    };

    Solution sol;
    vector<vector<int>> result = sol.employeeFreeTime(schedule);

    cout << "Free time intervals: ";
    printIntervals(result);
    // Expected output: [3,4]

    return 0;
}