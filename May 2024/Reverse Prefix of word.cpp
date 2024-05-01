#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int idx = -1;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == ch)
            {
                idx = i;
                break;
            }
        }
        if (idx == -1)
            return word;
        int i = 0, j = idx;
        while (i < j)
        {
            swap(word[i], word[j]);
            i++;
            j--;
        }
        return word;
    }
};