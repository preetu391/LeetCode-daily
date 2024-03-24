
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
    bool isPalindrome(ListNode *head)
    {
        if (head->next == nullptr)
            return true;
        if (head->next->next == nullptr)
            return head->val == head->next->val;
        ListNode *slow = head, *fast = head, *temp = head, *prev = nullptr;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        } // finding mid node of linked list
        while (slow)
        {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        } // reversing from the mid node
        while (prev)
        {
            if (prev->val != head->val)
                return false;
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};