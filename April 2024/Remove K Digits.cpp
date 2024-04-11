#include <bits/stdc++.h>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> st;
        for (int i = 0; i < num.size(); i++)
        {
            while (k > 0 && !st.empty() && num[i] < st.top())
            {
                k--;
                st.pop();
            }
            if (!st.empty() || num[i] != '0')
                st.push(num[i]);
        }
        while (k > 0 && !st.empty())
        {
            k--;
            st.pop();
        }
        if (st.empty())
            return "0";
        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};