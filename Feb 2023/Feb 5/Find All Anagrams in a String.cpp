#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    if (s.size() < p.size())
        return {};
    vector<int> ans;
    vector<int> si(26, 0), pi(26, 0);
    int window_size = p.size();
    int left = 0, right = 0;
    while (right < window_size)
    {
        si[s[right] - 'a']++;
        pi[p[right] - 'a']++;
        right++;
    }
    right--;
    while (right < s.size())
    {
        if (si == pi)
        {
            ans.push_back(left);
        }
        si[s[left] - 'a']--;
        left++;
        right++;
        if (right != s.size())
        {
            si[s[right] - 'a']++;
        }
    }
    return ans;
}

int main()
{
    string s1 = "ABABAB", s2 = "ABCCBABHJDGSHJ";
    findAnagrams(s1, s2);
    return 0;
}