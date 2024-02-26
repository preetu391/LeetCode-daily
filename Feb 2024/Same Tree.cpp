#include <bits/stdc++.h>
#include <stack>
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        stack<TreeNode *> st1, st2;
        st1.push(p);
        st2.push(q);
        while (!st1.empty() && !st2.empty())
        {
            p = st1.top();
            st1.pop();
            q = st2.top();
            st2.pop();
            if (p == NULL && q == NULL)
                continue;
            if (p == NULL || q == NULL)
                return false;
            if (p->val != q->val)
                return false;
            st1.push(p->left);
            st1.push(p->right);
            st2.push(q->left);
            st2.push(q->right);
        }
        return true;
    }
};