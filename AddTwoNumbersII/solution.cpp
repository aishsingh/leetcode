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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int num1 = 0;
        int num2 = 0;
        
        // Iterpret numbers from linked list inputs
        while (l1 != nullptr || l2 != nullptr)
        {
            if (l1 != nullptr)
            {
                num1 *= 10;         // shift digits up
                num1 += l1->val;    // add new digit 
            }
            if (l2 != nullptr)
            {
                num2 *= 10;         // shift digits up
                num2 += l2->val;    // add new digit 
            }
            
            // Increament down linked lists
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        
        // Sum numbers
        int sum = num1+num2;
        
        // Create result linked list
        ListNode* head = new ListNode(sum % 10);
        sum/=10;
        
        ListNode* tail = head;
        while (sum > 0)
        {
            int digit = sum % 10;
            sum /= 10;
            
            // Insert to linked list, starting from LSD (Least significant digit) to MSD (Most significant digit)
            ListNode* node = new ListNode(digit);
            tail->next = node;
            tail = node;
        }
        
        return head;
    }
};
