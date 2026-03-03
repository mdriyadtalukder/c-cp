/*
#fast and slow pointer for middleOfList.

fast(for even number) ba er next null(for odd) holei slow ta middle node hbe

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
*/
