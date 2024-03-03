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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *first = head;
        ListNode *second = head;
        ListNode *prev = head;
        int nn = n;
        if (head->next == nullptr)
            return nullptr;
        while (nn--)
        {
            second = second->next;
        }
        int m = 0;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            temp = temp->next;
            m++;
        }
        while (second != nullptr)
        {
            prev = first;
            first = first->next;
            second = second->next;
            m++;
        }
        if (n == m)
        {
            head = head->next;
            return head;
        }
        prev->next = first->next;
        return head;
    }
};