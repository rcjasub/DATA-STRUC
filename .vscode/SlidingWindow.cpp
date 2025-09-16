#include <iostream>
#include <vector>
using namespace std;

int FindMaxNum(vector<int> &nums, int k)
{
    int size = nums.size();
    if (size < k)
        return -1; // not enough elements

    int windowSum = 0;

    // get the sum of the first subarray(window)
    for (int i = 0; i < k; i++)
    {
        windowSum += nums[i];
    }

    // current max
    int maxSum = windowSum;

    for (int i = k; i < size; i++)
    {
        windowSum += nums[i];     // add the new element to the sum
        windowSum -= nums[i - k]; // remove the oldest element from the sum
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int minSubarrayLen(vector<int> &nums, int target)
{
//    int n = nums.size();
//     int left = 0, sum = 0;
//     int minLen = INT_MAX;

//     for (int right = 0; right < n; right++) {
//         sum += nums[right]; // expand window

//         // shrink while sum >= target
//         while (sum >= target) {
//             minLen = min(minLen, right - left + 1);
//             sum -= nums[left];
//             left++;
//         }
//     }

//     return (minLen == INT_MAX ? 0 : minLen);
}

int main()
{

    vector<int> nums = {2, 1, 5, 3, 2};
    int k = 3;
    cout << "Maximum sum of subarray of size " << k << " = "
         << FindMaxNum(nums, k) << endl;
}