class Solution {
private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        // If both subtrees are empty, they are symmetric
        if (t1 == nullptr && t2 == nullptr) return true;
        
        // If only one of them is empty, they are not symmetric
        if (t1 == nullptr || t2 == nullptr) return false;
        
        // Check if:
        // 1. Current node values match
        // 2. Left of t1 matches Right of t2
        // 3. Right of t1 matches Left of t2
        return (t1->val == t2->val) 
            && isMirror(t1->left, t2->right) 
            && isMirror(t1->right, t2->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        // An empty tree is symmetric
        if (root == nullptr) return true;
        
        // Compare the left and right subtrees
        return isMirror(root->left, root->right);
    }
};