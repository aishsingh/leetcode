/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) 
    {
        // use vector to keep track of linked list so we can reverse it later
        vector<ImmutableListNode*> list;

        // Build vector list from linked list
        auto currNode = head;
        while (currNode != nullptr)
        {
            list.push_back(currNode);

            // Iterate linked list
            currNode = currNode->getNext();
        }

        // print list in reverse order
        for (auto it=list.rbegin(); it!=list.rend(); it++)
        {
            (*it)->printValue();
        }
    }
};
