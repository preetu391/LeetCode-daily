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

void inOrder(TreeNode *node, vector<int> &result)
{
    if (node != NULL)
    {
        inOrder(node->left, result);
        result.push_back(node->val);
        inOrder(node->right, result);
    }
}

int minDiffInBST(TreeNode *root)
{
    vector<int> traversal;
    inOrder(root, traversal);
    int ans = INT_MAX;
    for (int i = 1; i < traversal.size(); i++)
    {
        ans = min(ans, abs(traversal[i] - traversal[i - 1]));
    }
    return ans;
}

int main()
{
    return 0;
}