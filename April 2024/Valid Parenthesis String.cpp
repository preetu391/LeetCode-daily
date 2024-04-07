#include <bits/stdc++.h>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        int cnt = 0, cntstar = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                cnt++;
            else if (s[i] == '*')
                cntstar++;
            else if (s[i] == ')')
            {
                if (cnt == 0)
                {
                    if (cntstar > 0)
                    {
                        cntstar--;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    cnt--;
                }
            }
        }
        cnt = 0;
        cntstar = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ')')
                cnt++;
            else if (s[i] == '*')
                cntstar++;
            else if (s[i] == '(')
            {
                if (cnt == 0)
                {
                    if (cntstar > 0)
                    {
                        cntstar--;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    cnt--;
                }
            }
        }
        return true;
    }
};