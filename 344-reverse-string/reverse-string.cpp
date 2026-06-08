class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            // Swap the characters at the left and right pointers
            std::swap(s[left], s[right]);
            
            // Move the pointers closer to the center
            left++;
            right--;
        }
    }
};