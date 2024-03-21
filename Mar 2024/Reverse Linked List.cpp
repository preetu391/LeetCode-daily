
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
    ListNode *recur(ListNode *curr, ListNode *prev)
    {
        if (curr == nullptr)
            return prev;
        ListNode *next = curr->next;
        curr->next = prev;
        return recur(next, curr);
    }
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *prev = nullptr, *curr = head;
        while (curr != nullptr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};