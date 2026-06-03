#include <vector>
#include <numeric> 

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        
        
        int expectedSum = n * (n + 1) / 2;
        
        
        int actualSum = std::accumulate(nums.begin(), nums.end(), 0);
        
        
        return expectedSum - actualSum;
    }
};