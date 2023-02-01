#include <bits/stdc++.h>
using namespace std;

string gcdOfStrings(string str1, string str2)
{
    if (str1 + str2 == str2 + str1)
    {
        return str1.substr(0, __gcd(str1.size(), str2.size()));
    }
    return "";
}

int main()
{
    string str1 = "ABABAB", str2 = "ABAB";
    gcdOfStrings(str1, str2);
    return 0;
}