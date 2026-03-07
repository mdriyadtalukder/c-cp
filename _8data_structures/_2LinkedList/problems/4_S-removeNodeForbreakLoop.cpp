/*


class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        bool isCycle = false;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                isCycle = true;
                break;
            }
        }
        if (!isCycle)
            return NULL;

        slow = head;
        ListNode *pre = NULL;

        while (slow != fast)
        {
            slow = slow->next;
            pre=fast; //always store previous value of fast
            fast = fast->next;
        }
            pre->next=NULL;//remove the cycle..last node k null er shthe point krse.
        return slow;
    }

*/