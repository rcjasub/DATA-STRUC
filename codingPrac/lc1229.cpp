#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

vector<int> minAvailableDuration(vector<vector<int>> &slots1, vector<vector<int>> &slots2, int duration)
{
    int i = 0;
    int j = 0;
    int n = slots1.size();
    int m = slots2.size();

    while (i < n && j < m)
    {
        int start1 = slots1[i][0];
        int start2 = slots2[j][0];

        int end1 = slots1[i][1];
        int end2 = slots2[j][1];

        int overlarpStart = max(start1, start2);
        int overlarpEnd = min(end1, end2);

        if (overlarpEnd - overlarpStart >= duration)
        {
            return {overlarpStart, overlarpStart + duration};
        }
        else
        {

            if (end1 < end2)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
    }

    return {};
}

int main()
{
}