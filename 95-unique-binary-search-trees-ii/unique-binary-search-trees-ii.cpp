/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }

private:
    vector<TreeNode*> buildTrees(int start, int end) {
        vector<TreeNode*> allTrees;
        
        // Base case: If start > end, no subtree can be formed. 
        // We push nullptr to represent an empty child.
        if (start > end) {
            allTrees.push_back(nullptr);
            return allTrees;
        }
        
        // Iterate through all values from start to end to make each a root
        for (int i = start; i <= end; ++i) {
            // 1. Generate all unique left subtrees
            vector<TreeNode*> leftSubtrees = buildTrees(start, i - 1);
            
            // 2. Generate all unique right subtrees
            vector<TreeNode*> rightSubtrees = buildTrees(i + 1, end);
            
            // 3. Connect the current root 'i' with all combinations of left & right subtrees
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* currentRoot = new TreeNode(i);
                    currentRoot->left = left;
                    currentRoot->right = right;
                    allTrees.push_back(currentRoot);
                }
            }
        }
        
        return allTrees;
    }
};