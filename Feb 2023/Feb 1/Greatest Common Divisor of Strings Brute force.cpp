#include <bits/stdc++.h>
using namespace std;

string gcdOfStrings(string str1, string str2)
{
    string ans = "";
    int small_sz = str1.size();
    if (str1.size() > str2.size())
        return gcdOfStrings(str2, str1);
    for (int i = 1; i <= small_sz; i++)
    {
        bool first = false, second = false;
        string temp = str1.substr(0, i);
        string t = "";
        int sz = str1.size() / i;
        while (sz--)
        {
            t += temp;
        }
        if (t == str1)
            first = true;
        t = "";
        sz = str2.size() / i;
        while (sz--)
        {
            t += temp;
        }
        if (t == str2)
            second = true;
        if (first && second)
            ans = temp;
    }
    return ans;
}

int main()
{
    string str1 = "ABABAB", str2 = "ABAB";
    gcdOfStrings(str1, str2);
    return 0;
}