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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

TreeNode *sortedListToBST(ListNode *head)
{
    if (head == nullptr)
        return nullptr;
    return convertToBST(head, nullptr);
}
TreeNode *convertToBST(ListNode *start, ListNode *end)
{
    if (start == end)
        return nullptr;
    ListNode *slow = start;
    ListNode *fast = start;
    while (fast != end && fast->next != end)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode *curr = new TreeNode(slow->val);
    curr->left = convertToBST(start, slow);
    curr->right = convertToBST(slow->next, end);
    return curr;
}

int main()
{
    return 0;
}