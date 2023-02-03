#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;
    string res = "";
    int jumps = (numRows - 1) * 2;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = i; j < s.size(); j += jumps)
        {
            res += s[j];
            if ((i > 0 && i < numRows - 1) && ((j + jumps - 2 * i) < s.size()))
            {
                res += s[j + jumps - 2 * i];
            }
        }
    }
    return res;
}

int main()
{
    string str1 = "ABABAB";
    int n = 2;
    convert(str1, n);
    return 0;
}