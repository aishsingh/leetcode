// Help from https://leetcode.com/problems/split-linked-list-in-parts/solutions/5752989/beats-100-explained-with-video-c-java-python-o-n-time-o-k-space-explained-in-detail
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        vector<ListNode*> result(k);

        // Traverse linked list to find how many nodes there are in total
        ListNode* currNodeMainList  = head;
        int linkedListSize          = 0;

        while (currNodeMainList != nullptr)
        {
            // Iterate linked list
            currNodeMainList = currNodeMainList->next;
            linkedListSize++;
        }


        // Traverse linked list again creating new sublists based on the calculates split
        int nodeSplitSize           = linkedListSize / k;
        int nodeSplitExtras         = linkedListSize % k;
        currNodeMainList            = head;
        ListNode* prevNodeMainList  = currNodeMainList;

        int subListNodeSize         = 0;
        for (int i = 0; i < k; i++) {
            // create the i-th part
            ListNode* newPart = currNodeMainList;
            // calculate size of i-th part
            int currentSize = nodeSplitSize;
            if (nodeSplitExtras > 0) {
                nodeSplitExtras--;
                currentSize++;
            }

            // traverse to end of new part
            int j = 0;
            while (j < currentSize) {
                prevNodeMainList = currNodeMainList;
                if (currNodeMainList != nullptr) {
                    currNodeMainList = currNodeMainList->next;
                }
                j++;
            }

            // cut off the rest of linked list
            if (prevNodeMainList != nullptr) {
                prevNodeMainList->next = nullptr;
            }

            result[i] = newPart;
        }

        // fill with empty linked lists
        while (result.size() < k)
        {
            result.push_back(nullptr);
        }

        return result;
    }
};
