#include <bits/stdc++.h>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int largestRectangle(vector<int> &dp)
    {
        stack<int> st;
        st.push(-1);
        int max_area = 0;
        for (int i = 0; i <= dp.size(); i++)
        {
            int val = (i == dp.size()) ? -1 : dp[i];
            while (st.top() != -1 && dp[st.top()] > val)
            {
                int height = dp[st.top()];
                st.pop();
                int width = i - st.top() - 1;
                max_area = max(max_area, width * height);
            }
            st.push(i);
        }
        return max_area;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        if (n + m == 2)
            return matrix[0][0] == '1';
        vector<int> dp(m, 0);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '0')
                    dp[j] = 0;
                else
                    dp[j]++;
            }
            res = max(res, largestRectangle(dp));
        }
        return res;
    }
};