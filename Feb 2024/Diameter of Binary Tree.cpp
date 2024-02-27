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

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
    int height(TreeNode *root, int &max_d)
    {
        if (root == NULL)
            return 0;
        int left_h = height(root->left, max_d);
        int right_h = height(root->right, max_d);
        max_d = max(max_d, left_h + right_h);
        return 1 + max(left_h, right_h);
    }
};