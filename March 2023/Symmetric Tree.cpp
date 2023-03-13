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

bool isEqual(TreeNode *leftNode, TreeNode *rightNode)
{
    if (!leftNode || !rightNode)
        return leftNode == rightNode;
    if (leftNode->val == rightNode->val)
    {
        return isEqual(leftNode->left, rightNode->right) && isEqual(leftNode->right, rightNode->left);
    }
    return false;
}
bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    return isEqual(root->left, root->right);
}

int main()
{
    return 0;
}