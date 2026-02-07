/*
jokhni fast==slow hbe tokhni slow=head hbe and slow and fast 2 jon kei +1 kore agabo..
then abr jokhn 2 jon soman hbe tokhni peye jbo oi node jetar jnno loop hocce

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
        while (slow != false)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

*/