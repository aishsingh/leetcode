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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummyHead = new ListNode();
        ListNode *tail = dummyHead;

        while (list1 != nullptr || list2 != nullptr)
        {
            int val1            = (list1 != nullptr) ? list1->val : INT_MAX;
            int val2            = (list2 != nullptr) ? list2->val : INT_MAX;
            bool val1Smaller    = (val1 < val2);

            int newVal          = (val1Smaller ? val1 : val2);

            // Add new sum node 
            ListNode *newNode = new ListNode(newVal);
            tail->next = newNode;   // add new sum to end of result linked list
            tail = tail->next;      // iterate tail down linked list


            // iterate down linked list one item from one of the lists at a time
            if (val1Smaller && list1 != nullptr)
            {
                list1 = list1->next;
            }
            else if (!val1Smaller && list2 != nullptr)
            {
                list2 = list2->next;
            }
        }

        // need to do this to remove inital leading 0 value from dummy head
        ListNode* result = dummyHead->next;
        delete dummyHead;
    
        return result;
    }
};
