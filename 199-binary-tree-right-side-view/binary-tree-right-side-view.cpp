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
    void rightViewUtil(TreeNode* root, int level, vector<int>& result) {
        if (root == nullptr) return;

        // If this is the first time we are visiting this level
        if (level == result.size()) {
            result.push_back(root->val);
        }

        // Core logic: Traverse RIGHT subtree first, then LEFT subtree
        rightViewUtil(root->right, level + 1, result);
        rightViewUtil(root->left, level + 1, result);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        rightViewUtil(root, 0, result);
        return result;
    }
};