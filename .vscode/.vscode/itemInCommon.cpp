#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;

//O(n^2)
bool FindCommon(vector<int> arr1, vector<int> arr2)
{
    for(auto i : arr1)
    {
        for(auto j : arr2)
        {
            if(i == j)
            {
                cout<<"Common element: "<<i<<endl;
                return true;
            }
        }
    }

    return false;
}

/////////////////////////////////////////////////
//O(n)
bool FindCommonHash(vector<int> arr1, vector<int> arr2)
{
    unordered_map<int, bool> myMap;

    for(auto i : arr1)
    {
         myMap.insert({i, true});
    }

    for(auto j : arr2)
    {
        if(myMap[j]) return true;
    }

   return false;
}

/////////////////////////////////////

vector<int> FindDuplicates(vector<int> arr1)
{
    unordered_map<int, int> myMap;
    vector<int> duplicate;
    
    for(auto i : arr1)
    {
        myMap[i]++;
    }

    for(auto i : myMap)
    {
        if(i.second > 1) 
        {
        duplicate.push_back(i.first);
        cout<<i.first<<" : "<<i.second<<endl;
        }
    }

    return duplicate;
}



int main()
{
    vector<int> arr1 = {1, 7, 3, 4, 7};
    vector<int> arr2 = {6, 7, 8, 9, 10};

    cout<<FindCommonHash(arr1, arr2)<<endl;
    cout<<FindDuplicates(arr1).size()<<endl;

}