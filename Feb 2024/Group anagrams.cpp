#include <bits/stdc++.h>
using namespace std;
#include <map>

// using hashmap
class Solution_hashmap
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto it : mp)
        {
            vector<string> temp;
            for (auto i : it.second)
            {
                temp.push_back(i);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// using count sort
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<vector<int>, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++)
        {
            vector<int> freq(26);
            for (char c : strs[i])
            {
                freq[c - 'a']++;
            }
            mp[freq].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};