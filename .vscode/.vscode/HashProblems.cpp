#include<vector>
#include<unordered_map>
#include<iostream>

class HashProblems 
    {
        public:

        std::vector<int> twoSum(std::vector<int>& nums, int target)
        {
            std::unordered_map<int, int> num_map;

        int i = 0;
        for(auto num : nums)
        {
            int complement = target - num;
            if(num_map.find(complement) != num_map.end())
            {
                return {num_map[complement], i};
            }
            num_map[num] = i;
            i++;
        }

        return {};

        }  

        std::vector<char>  firstNonReapetingChar(std::string str)
      {
        std::unordered_map<char, int> char_count_map;
        std::vector<char> results;

        for(char c : str)
        {
            char_count_map[c]++;
        }

        for(char c : str)
        {
            if(char_count_map[c] == 1)
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
        std::vector<int> nums = {2, 7, 11, 15};
        int target = 18;
        std::vector<int> result = hp.twoSum(nums, target);
        for(int i : result)
        {
            std::cout << i << " ";
        }

        std::cout << std::endl;
        std::string str = "swiss";
        std::vector<char>  first_unique = hp.firstNonReapetingChar(str);
         
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