/********************************************
Solution to LeetCode Daily Question 05-13-2024. 

Problem:
You are given the root of a full binary tree with the following properties:

Leaf nodes have either the value 0 or 1, where 0 represents False and 1 represents True.
Non-leaf nodes have either the value 2 or 3, where 2 represents the boolean OR and 3 represents the boolean AND.

The evaluation of a node is as follows:

If the node is a leaf node, the evaluation is the value of the node, i.e. True or False.
Otherwise, evaluate the node's two children and apply the boolean operation of its value with the children's evaluations.
Return the boolean result of evaluating the root node.

Solution:
Using DFS, each internal node expression an be evaluated. The value of expression at a particular node will be the result of the expression in the left and right subtrees ORed or ADDed depending on the value in the node. For leaf nodes, the value is the val field of the node itself.
The evaluation for the left and the right subtree of the current node is done recursively. When a leaf node is encountered, the val is returned.
Complexity:
Time complexity: O(n)
Space complexity: O(n)
n is number of nodes in the tree
********************************************/

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
    bool evaluateTree(TreeNode* root) {
        if(root -> left == NULL && root -> right == NULL)
            return root -> val;
        if(root -> val == 2)
            return evaluateTree(root -> left) || evaluateTree(root -> right);
        else 
            return evaluateTree(root -> left) && evaluateTree(root -> right);
    }
};
