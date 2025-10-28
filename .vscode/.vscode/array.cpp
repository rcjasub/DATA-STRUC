#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{

    for (int i = 0; i < nums.size(); i++)
    {
        int needed = target - nums[i];

        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] == needed)
            {
                return {i, j};
            }
        }
    }
    return {};
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{

    int a = 20;
    int b = 3;

    swap(a, b);
    cout << a << " " << b << endl; // Output: 3 20
    return 0;
};