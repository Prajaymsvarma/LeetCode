class Solution {
public:
    int numTrees(int n) {
        // dp[i] will store the number of unique BSTs that can be formed with i nodes
        vector<int> dp(n + 1, 0);
        
        // Base cases
        dp[0] = 1; // An empty tree is 1 unique BST
        dp[1] = 1; // A tree with 1 node is 1 unique BST
        
        // Fill the DP table for all node counts from 2 up to n
        for (int nodes = 2; nodes <= n; ++nodes) {
            for (int root = 1; root <= nodes; ++root) {
                int left_nodes = root - 1;
                int right_nodes = nodes - root;
                
                dp[nodes] += dp[left_nodes] * dp[right_nodes];
            }
        }
        
        return dp[n];
    }
};