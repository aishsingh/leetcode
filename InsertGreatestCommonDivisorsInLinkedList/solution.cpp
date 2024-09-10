/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
        ListNode* currNode = head;

        while (currNode != nullptr)
        {
            // find common devisor
            if (currNode->next != nullptr)
            {
                int a = currNode->val;
                int b = currNode->next->val;
                int devisor = min(a, b);

                while ((a % devisor) != 0 || 
                       (b % devisor) != 0)
                {
                    devisor--;
                }

                // found devisor node
                ListNode* devisorNode = new ListNode(devisor);

                // insert into linked list
                devisorNode->next = currNode->next;
                currNode->next = devisorNode;
                
                // iterate to devisor node so it will iterate past it in the next statement
                currNode = currNode->next;
            }

            // iterate linked list
            currNode = currNode->next;
        }

        return head; 
    }
};
