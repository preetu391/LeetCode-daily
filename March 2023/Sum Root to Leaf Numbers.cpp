#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int sumNumbers(TreeNode *root)
{
    long long sum = 0;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto node = q.front().first;
        auto curr_sum = q.front().second;
        q.pop();
        curr_sum = curr_sum * 10 + node->val;
        if (!node->left && !node->right)
        {
            sum += curr_sum;
        }
        if (node->left)
            q.push({node->left, curr_sum});
        if (node->right)
            q.push({node->right, curr_sum});
    }
    return int(sum);
}

int main()
{
    return 0;
}