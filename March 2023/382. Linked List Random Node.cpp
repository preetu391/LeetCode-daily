#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    int len = 0;
    ListNode *H;

public:
    Solution(ListNode *head)
    {
        H = head;
        ListNode *temp = head;
        while (temp)
        {
            len++;
            temp = temp->next;
        }
    }

    int getRandom()
    {
        int random_number = rand() % len;
        ListNode *random_node = H;
        while (random_number--)
        {
            random_node = random_node->next;
        }
        return random_node->val;
    }
};

int main()
{
    return 0;
}