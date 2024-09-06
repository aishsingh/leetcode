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
    ListNode* removeElements(ListNode* head, int val) 
    {
        // Sentinel node used as a temprary head to ensure all nodes in the list have a prev node so they can be checked 
        auto sentinelNode       = new ListNode(0);
        sentinelNode->next      = head;

        auto prevNode           = sentinelNode;
        auto currNode           = head;
        ListNode* nodeToDelete  = nullptr;

        // traverse linked list
        while (currNode != nullptr)
        {
            if (currNode->val == val)
            {
                // remove current node by skipping current node in the linked list
                prevNode->next = currNode->next;
            }
            else
            {
                prevNode = currNode;
            }

            currNode = currNode->next;

            if (nodeToDelete != nullptr) 
            {
                delete nodeToDelete;
                nodeToDelete = nullptr;
            }
        }

        // remove sentinel node now that the list has been found
        ListNode* resultHead = sentinelNode->next;
        delete sentinelNode;

        return resultHead;
    }
};
