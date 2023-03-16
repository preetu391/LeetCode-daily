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

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    map<int, int> m;
    for (int i = 0; i < inorder.size(); i++)
    {
        m[inorder[i]] = i;
    }
    int n = postorder.size() - 1;
    TreeNode *root = helper(postorder, m, n, 0, inorder.size() - 1);
    return root;
}
TreeNode *helper(vector<int> postorder, map<int, int> &m, int &rootIdx, int start, int end)
{
    if (start > end)
        return NULL;
    int root = postorder[rootIdx--];
    int idx = m[root];
    TreeNode *rootNode = new TreeNode(root);

    rootNode->right = helper(postorder, m, rootIdx, idx + 1, end);
    rootNode->left = helper(postorder, m, rootIdx, start, idx - 1);

    return rootNode;
}

int main()
{
    return 0;
}