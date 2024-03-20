
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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *p = list1, *q = list1;
        int k = b - a + 1;
        for (int i = 1; i <= k; i++)
            q = q->next;
        for (int i = 1; i < a; i++)
        {
            p = p->next;
            q = q->next;
        }
        ListNode *last_node_list2 = list2;
        while (last_node_list2->next != nullptr)
        {
            last_node_list2 = last_node_list2->next;
        }
        p->next = list2;
        last_node_list2->next = q->next;
        return list1;
    }
};