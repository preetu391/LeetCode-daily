#include <bits/stdc++.h>
#include <queue>
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
    bool isEvenOddTree(TreeNode *root)
    {
        int level = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            if (level % 2 == 1)
            {
                int prev = INT_MAX;
                for (int i = 0; i < size; i++)
                {
                    TreeNode *node = q.front();
                    q.pop();
                    if (node->val % 2 == 1)
                        return false;
                    if (node->val >= prev)
                    {
                        return false;
                    }
                    prev = node->val;
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
            }
            else
            {
                int prev = INT_MIN;
                for (int i = 0; i < size; i++)
                {
                    TreeNode *node = q.front();
                    q.pop();
                    if (node->val % 2 == 0)
                        return false;
                    if (node->val <= prev)
                    {
                        return false;
                    }
                    prev = node->val;
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
            }
            level++;
        }
        return true;
    }
};