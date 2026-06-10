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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* curr = root;
        int count = 0;
        
        // Standard In-order Traversal (Left -> Root -> Right)
        while (curr != nullptr || !s.empty()) {
            // Reach the leftmost node of the current node
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
            
            // Current must be nullptr at this point, pop from stack
            curr = s.top();
            s.pop();
            
            // Increment the count of visited nodes
            count++;
            
            // If count equals k, we found the kth smallest element
            if (count == k) {
                return curr->val;
            }
            
            // Move to the right subtree
            curr = curr->right;
        }
        
        return -1; // Fallback
    }
};