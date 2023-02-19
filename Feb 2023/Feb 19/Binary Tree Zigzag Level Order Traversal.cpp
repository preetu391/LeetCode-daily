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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (root == nullptr)
        return {};
    int flag = 1;
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        vector<int> level;
        for (int i = 0; i < n; i++)
        {
            TreeNode *curr = q.front();
            level.push_back(q.front()->val);
            q.pop();
            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
        }
        if (flag != 1)
        {
            reverse(level.begin(), level.end());
            ans.push_back(level);
            flag = 1;
        }
        else
        {
            ans.push_back(level);
            flag = 0;
        }
    }
}
int main()
{
    return 0;
}