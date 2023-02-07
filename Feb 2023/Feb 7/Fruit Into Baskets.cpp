#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int> &fruits)
{
    int ans = 0;
    map<int, int> basket;
    int left = 0, right = 0;
    while (right < fruits.size())
    {
        basket[fruits[right]]++;
        if (basket.size() <= 2)
            ans = max(ans, right - left + 1);
        else
        {
            basket[fruits[left]]--;
            if (basket[fruits[left]] == 0)
                basket.erase(fruits[left]);
            left++;
        }
        right++;
    }
    return ans;
}

int main()
{
    vector<int> v = {1, 2, 3, 3, 3, 5};
    totalFruit(v);
    return 0;
}