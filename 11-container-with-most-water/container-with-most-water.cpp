#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max_water = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            // Calculate current width
            int width = right - left;
            
            // Calculate current area based on the shorter wall
            int current_water = width * std::min(height[left], height[right]);
            
            // Keep track of the maximum water found so far
            max_water = std::max(max_water, current_water);
            
            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};