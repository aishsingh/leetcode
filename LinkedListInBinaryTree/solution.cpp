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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        // Use DFS algorithm to see if all elements in linked list are found in sequence
        // Traverse tree once looking for linked list nodes

        return dfs(head, head, root);
    }

    bool dfs(ListNode* headListNode, ListNode* currListNode, TreeNode* currTreeNode)
    {
        if (currListNode == nullptr)
            return true;    // found all items of the list in the tree

        if (currTreeNode == nullptr)
            return false;

        if (currTreeNode->val == currListNode->val)
        {
            // list node and tree node match, see if the next list node and tree nodes match as well
            currListNode = currListNode->next;
        }
        else if (currTreeNode->val == headListNode->val)
        {
            // list node and tree node match, see if the next list node and tree nodes match as well
            headListNode = headListNode->next;
        }
        else
        {
            // list item procedding head was wasnt found
            // reset back to head as a sub path must be connected and ordered in the list sequence
            currListNode = headListNode;
        }

        return (dfs(headListNode, currListNode, currTreeNode->left) || dfs(headListNode, currListNode, currTreeNode->right));
    }
};
