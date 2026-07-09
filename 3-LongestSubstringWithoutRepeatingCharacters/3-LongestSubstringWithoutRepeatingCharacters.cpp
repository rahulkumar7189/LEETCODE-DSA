// Last updated: 7/9/2026, 8:50:00 PM
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Vector to store the last seen index of characters (initialized to -1)
        // 128 covers all standard ASCII characters (letters, digits, symbols, spaces)
        std::vector<int> last_seen(128, -1);
        
        int max_len = 0;
        int left = 0; // Left boundary of the sliding window
        
        for (int right = 0; right < s.length(); ++right) {
            char current_char = s[right];
            
            // If the character was seen before AND its last position is inside the current window
            if (last_seen[current_char] >= left) {
                // Move the left pointer past the last occurrence of this character
                left = last_seen[current_char] + 1;
            }
            
            // Update the last seen position of the current character
            last_seen[current_char] = right;
            
            // Calculate the current window size and update max_len
            max_len = std::max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};