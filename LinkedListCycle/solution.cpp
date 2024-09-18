/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        // Using Floyd's Cycle-Finding Algorithm
        // SEE https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/
        auto slowPtr = head;
        auto fastPtr = head;

        while (slowPtr != nullptr && 
               fastPtr != nullptr && 
               fastPtr->next != nullptr)    // this extra check needed only for the fast pointer as it will move 2 nodes at a time
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;

            if (slowPtr == fastPtr)
            {
                // slow pointer and fast pointer point to the same node
                // this can only occur at this point if a cycle occured in the linked list
                // cycle detected
                return true;
            }
        }

        // reached end of linked list
        // cycle not detected
        return false;
    }
};
