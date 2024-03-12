#include <bits/stdc++.h>
#include <map>
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
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        int sum = 0;
        map<int, ListNode *> mp;
        mp[0] = dummy;
        while (head != NULL)
        {
            sum += head->val;
            if (mp.find(sum) != mp.end())
            {
                ListNode *node = mp[sum], *start = mp[sum];
                int s = sum;
                while (node != head)
                {
                    node = node->next;
                    s += node->val;
                    if (node != head)
                    {
                        mp.erase(s);
                    }
                    start->next = head->next;
                }
            }
            else
            {
                mp[sum] = head;
            }
            head = head->next;
        }
        return dummy->next;
    }
};