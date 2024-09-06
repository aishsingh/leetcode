#include <algorithm>

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        // Sort nums so a more efficient binary search can be used later to compare vals
        sort(nums.begin(), nums.end());

        // temporary node used as the placeholder for a node before head so head can be removed if neccessary
        auto sentinelNode       = new ListNode(0);
        sentinelNode->next      = head;

        auto currNode           = head;
        auto prevNode           = sentinelNode;

        ListNode* toDeleteNode  = nullptr;

        // Traverse linked list comparing each node value to nums and removing if they have the same value
        while (currNode != nullptr)
        {
            if (binary_search(nums.begin(), nums.end(), currNode->val))
            {
                // val found in nums
                // Unlink node from list
                prevNode->next = currNode->next;
                toDeleteNode = currNode;
            }
            else
            {
                // move to next node
                prevNode = currNode;
            }

            // move to next node
            currNode = currNode->next;

            // delete unlinked node
            if (toDeleteNode != nullptr)
            {
                delete toDeleteNode;
                toDeleteNode = nullptr;
            }
        }

        // Delete temporay sentinel node and return the new head
        ListNode* resultHead = sentinelNode->next;
        delete sentinelNode;

        return resultHead;
    }
};
