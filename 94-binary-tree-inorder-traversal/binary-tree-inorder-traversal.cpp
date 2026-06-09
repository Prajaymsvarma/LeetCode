/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
    
private:
    void helper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        
        helper(node->left, result);  // Traverse Left
        result.push_back(node->val); // Visit Root
        helper(node->right, result); // Traverse Right
    }
};