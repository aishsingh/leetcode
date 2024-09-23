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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        auto curNodeA = headA;
        auto curNodeB = headB;

        // Map the number of times each node is visited
        unordered_map<ListNode*, int> nodeVisitCount;

        while (curNodeA != nullptr || curNodeB != nullptr)
        {
            // Add nodes to map to keep track of visited nodes
            // And also check for intersected nodes

            if (curNodeA != nullptr)
            {
                if (++nodeVisitCount[curNodeA] > 1)
                    return curNodeA;
            }

            if (curNodeB != nullptr)
            {
                if (++nodeVisitCount[curNodeB] > 1)
                    return curNodeB;
            }

            // iterate to next nodes to continue search

            if (curNodeA != nullptr)
                curNodeA = curNodeA->next;

            if (curNodeB != nullptr)
                curNodeB = curNodeB->next;
        }

        // if we reached here then no intersection node was found
        return nullptr; 
    }
};
