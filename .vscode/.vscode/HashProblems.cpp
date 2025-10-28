#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class HashProblems
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> num_map; // value -> index

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end())
            {
                return {num_map[complement], i};
            }
            num_map[nums[i]] = i;
        }

        return {};
    }

    bool containsDuplicate(std::vector<int> &nums)
    {
        std::unordered_map<int, bool> num_map;

        for (auto num : nums)
        {
            if (num_map.find(num) != num_map.end())
            {
                return true;
            }
            num_map[num] = true;
        }

        return false;
    }

    int singleNumber(std::vector<int> &nums)
    {
        int result = 0;
        for (int i : nums)
        {
            result ^= i;
        }

        return result;
    }

    std::vector<int> sNumber(std::vector<int> &nums)
    {
        std::unordered_map<int, int> myMap;
        std::vector<int> v;

        for (auto i : nums)
        {
            myMap[i]++;
        }

        for (auto i : nums)
        {
            if (myMap[i] == 1)
            {
                v.push_back(i);
            }
        }

        return v;
    }

    ///////////////////////////////////////////////////////////////////////
    vector<vector<int>> SubSet(vector<int> &nums)
    {
        vector<vector<int>> result;
        result.push_back({});

        for (int num : nums)
        {
            int n = result.size();
            for (int i = 0; i < n; i++)
            {
                vector<int> subA = result[i];
                subA.push_back(num);
                result.push_back(subA);
            }
        }

        return result;
    }

    ////////////////////////////////////////////////////////////////////////

    std::vector<char> firstNonReapetingChar(std::string str)
    {
        std::unordered_map<char, int> char_count_map;
        std::vector<char> results;

        for (char c : str)
        {
            char_count_map[c]++;
        }

        for (char c : str)
        {
            if (char_count_map[c] == 1)
            {
                results.push_back(c);
            }
        }

        return results;
    }
};

int main()
{
    HashProblems hp;
    std::vector<int> nums = {
        2,
        7,
        11,
    };
    int target = 9;

    // auto s = hp.singleNumber(nums);
    // std::cout << "Single Numbber " << s << std::endl;

    vector<vector<int>> res = hp.SubSet(nums);

    for (auto &subset : res)
    {
        cout << "[";
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i];
            if (i != subset.size() - 1)
                cout << ",";
        }
        cout << "] ";
    }

    cout<<endl;

    /////////////////////////////////////////////////////////////

    std::vector<int> result = hp.twoSum(nums, target);
    for (int i : result)
    {
        std::cout << i << " ";
    }

    ///////////////////////////////////////////////

    std::cout << std::endl;
    std::string str = "swiss";
    std::vector<char> first_unique = hp.firstNonReapetingChar(str);

    if (first_unique.empty())
    {
        std::cout << "No non-repeating character found." << std::endl;
    }
    else
    {
        std::cout << "First non-repeating characters: ";
        for (char c : first_unique)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}