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

bool isCompleteTree(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    bool ok = false;
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        if (curr == NULL)
            ok = true;
        else
        {
            q.push(curr->left);
            q.push(curr->right);
            if (ok)
                return false;
        }
    }
    return true;
}

int main()
{
    return 0;
}