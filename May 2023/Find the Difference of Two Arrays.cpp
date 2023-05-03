#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> answer;
    map<int, int> mp1, mp2;
    for (int i = 0; i < nums1.size(); i++)
    {
        mp1[nums1[i]]++;
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        mp2[nums2[i]]++;
    }
    vector<int> v1, v2;
    for (auto &it : mp1)
    {
        if (mp2.find(it.first) != mp2.end())
        {
            continue;
        }
        else
        {
            v1.push_back(it.first);
        }
    }
    for (auto &it : mp2)
    {
        if (mp1.find(it.first) != mp1.end())
        {
            continue;
        }
        else
        {
            v2.push_back(it.first);
        }
    }
    answer.push_back(v1);
    answer.push_back(v2);
    return answer;
}

int main()
{
    return 0;
}