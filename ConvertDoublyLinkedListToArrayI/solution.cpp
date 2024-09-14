/**
 * Definition for doubly-linked list.
 * class Node {
 *     int val;
 *     Node* prev;
 *     Node* next;
 *     Node() : val(0), next(nullptr), prev(nullptr) {}
 *     Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *     Node(int x, Node *prev, Node *next) : val(x), next(next), prev(prev) {}
 * };
 */
class Solution {
public:
	vector<int> toArray(Node *head)
    {
        // use vector to keep track of linked list so we can reverse it later
        vector<int> result;

        // Build vector list from linked list
        auto currNode = head;
        while (currNode != nullptr)
        {
            result.push_back(currNode->val);

            // Iterate linked list
            currNode = currNode->next;
        }

        return result;
    }
};
