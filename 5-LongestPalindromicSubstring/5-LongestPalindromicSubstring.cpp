// Last updated: 7/9/2026, 8:49:59 PM
#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        
        int start = 0; // Tracking start index of the longest palindrome found
        int max_len = 0; // Tracking length of the longest palindrome found
        
        for (int i = 0; i < s.length(); ++i) {
            // Case 1: Odd length palindrome centered at index i
            int len1 = expandAroundCenter(s, i, i);
            
            // Case 2: Even length palindrome centered between indices i and i + 1
            int len2 = expandAroundCenter(s, i, i + 1);
            
            // Get the maximum length found from this center point
            int current_max = std::max(len1, len2);
            
            // If it's longer than our previous record, update the boundaries
            if (current_max > max_len) {
                max_len = current_max;
                // Calculate the true starting position of this substring
                start = i - (current_max - 1) / 2;
            }
        }
        
        return s.substr(start, max_len);
    }

private:
    int expandAroundCenter(const std::string& s, int left, int right) {
        // Expand outwards as long as pointers are in bounds and characters match
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Returns the length of the valid palindromic substring
        return right - left - 1;
    }
};