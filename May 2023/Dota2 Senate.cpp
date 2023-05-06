#include <bits/stdc++.h>
using namespace std;

string predictPartyVictory(string senate)
{
    stack<char> st;
    for (int i = 0; i < senate.size(); i++)
    {
        if (st.empty())
        {
            st.push(senate[i]);
        }
        else
        {
            if (senate[i] != st.top())
            {
                char x = st.top();
                st.pop();
                senate += x;
            }
            else
            {
                st.push(senate[i]);
            }
        }
    }
    if (st.top() == 'R')
        return "Radiant";
    else
        return "Dire";
    return "";
}

int main()
{
    return 0;
}