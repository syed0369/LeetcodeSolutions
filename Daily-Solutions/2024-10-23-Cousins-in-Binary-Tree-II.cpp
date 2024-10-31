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
    TreeNode* replaceValueInTree(TreeNode* root) {
        int sum, sz, level;
        queue<TreeNode*> nodes;
        TreeNode* node;
        nodes.push(root);
        vector<int> level_sum;
        while(!nodes.empty()) {
            sum = 0;
            sz = nodes.size();
            while(sz--) {
                node = nodes.front();
                nodes.pop();
                sum += node -> val;
                if(node -> left)    nodes.push(node -> left);
                if(node -> right)   nodes.push(node -> right);
            }
            level_sum.push_back(sum);
        }
        
        nodes.push(root);
        root -> val = 0;
        level = 0;
        while(!nodes.empty()) {
            sz = nodes.size();
            level++;
            while(sz--) {
                node = nodes.front();
                nodes.pop();
                if(node -> left) {
                    node -> left -> val = level_sum[level] - (node -> left -> val) - ((node -> right)? (node -> right -> val) : 0);
                    nodes.push(node -> left);
                }
                if(node -> right) {
                    node -> right -> val = ((node -> left)? (node -> left -> val) : level_sum[level] - node -> right -> val);
                    nodes.push(node -> right);
                }
            }
        }
        return root;
    }
};
