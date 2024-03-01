#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int num_1 = -1, num_0 = 0;
        string ans = "";
        for (auto c : s)
        {
            if (c == '1')
                num_1++;
            else
                num_0++;
        }
        ans = string(num_1, '1') + string(num_0, '0') + '1';
        return ans;
    }
};