#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{
    if (haystack.size() < needle.size())
        return -1;
    if (haystack.size() == needle.size() && (haystack == needle))
        return 0;
    int x = haystack.size(), y = needle.size();
    for (int i = 0; i <= (x - y); i++)
    {
        string s = haystack.substr(i, y);
        if (s == needle)
            return i;
    }
    return -1;
}

int main()
{
    return 0;
}