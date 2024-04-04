#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int depth = 0, ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                depth++;
                ans = max(depth, ans);
            }
            if (s[i] == ')')
                depth--;
        }
        return ans;
    }
};