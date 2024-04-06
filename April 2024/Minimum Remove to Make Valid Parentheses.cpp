#include <bits/stdc++.h>
#include <string>
#include <stack>
using namespace std;

// Solution 1 using stack
class Solution1
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')')
            {
                if (st.empty())
                {
                    s[i] = '$';
                }
                else
                {
                    st.pop();
                }
            }
        }
        while (!st.empty())
        {
            s[st.top()] = '$';
            st.pop();
        }
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '$')
                ans += s[i];
        }
        return ans;
    }
};

// Solution 2 without extra space
class Solution2
{
public:
    string minRemoveToMakeValid(string s)
    {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                cnt++;
            else if (s[i] == ')')
            {
                if (cnt == 0)
                {
                    s[i] = '$';
                }
                else
                {
                    cnt--;
                }
            }
        }
        cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ')')
                cnt++;
            else if (s[i] == '(')
            {
                if (cnt == 0)
                {
                    s[i] = '$';
                }
                else
                {
                    cnt--;
                }
            }
        }
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '$')
                ans += s[i];
        }
        return ans;
    }
};