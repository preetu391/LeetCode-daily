#include <bits/stdc++.h>
using namespace std;

map<char, int> sequence;
bool cmp(string a, string b)
{
    int n = min(a.length(), b.length());
    for (int i = 0; i < n; i++)
    {
        if (sequence[a[i]] > sequence[b[i]])
        {
            return false;
        }
        else if (sequence[a[i]] < sequence[b[i]])
        {
            return true;
        }
    }
    if (a.length() <= b.length())
    {
        return true;
    }
    return false;
}

bool isAlienSorted(vector<string> &words, string order)
{
    for (int i = 1; i <= 26; i++)
    {
        sequence[order[i - 1]] = i;
    }
    vector<string> temp = words;
    sort(temp.begin(), temp.end(), cmp);
    if (temp == words)
        return true;
    return false;
}

int main()
{
    vector<string> words = {"word", "row"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    isAlienSorted(words, order);
    return 0;
}