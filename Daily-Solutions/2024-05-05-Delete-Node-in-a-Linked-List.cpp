/********************************************
Solution to LeetCode Daily Question 05-05-2024. 

Problem:
There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.

Solution:
Since only forward traversal is possible, we cannot delete the node with the address given as the argument to the function. The idea is to copy the value of its successor to the val field of the node. Then the successor the node has to be deleted which can be done by setting the next pointer of the node originally to be deleted to reference the node pointed by its successor.

Complexity:
Time complexity: O(1) 
Space complexity: O(1)

********************************************/
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
    void deleteNode(ListNode* node) {
        ListNode* nextnode;
        nextnode = node -> next;
        node -> val = nextnode -> val;
        node -> next = nextnode -> next;
    }
};
