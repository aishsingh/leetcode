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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev      = nullptr;
        ListNode* current   = head;
        ListNode* next      = nullptr;

        while (current != nullptr)
        {
            // store next
            next = current->next;

            // reverse next node
            current->next = prev;

            // move pointers one pos ahead
            prev = current;
            current = next;
        }

        return prev;
    }
};

/*  
 * Got help from https://www.geeksforgeeks.org/reverse-a-linked-list/
 */
