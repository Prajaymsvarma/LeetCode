#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        
        if (nums.empty()) return 0;
        
        
        int i = 0; 
        
        
        for (int j = 1; j < nums.size(); j++) {
            
            if (nums[j] != nums[i]) {
                i++;             
                nums[i] = nums[j]; 
            }
        }
        
        // The number of unique elements is i + 1 (since index is 0-based)
        return i + 1;
    }
};