// Last updated: 7/6/2026, 4:55:16 PM
1#include <string>
2#include <algorithm>
3
4class Solution {
5public:
6    std::string longestPalindrome(std::string s) {
7        if (s.empty()) return "";
8        
9        int start = 0; // Tracking start index of the longest palindrome found
10        int max_len = 0; // Tracking length of the longest palindrome found
11        
12        for (int i = 0; i < s.length(); ++i) {
13            // Case 1: Odd length palindrome centered at index i
14            int len1 = expandAroundCenter(s, i, i);
15            
16            // Case 2: Even length palindrome centered between indices i and i + 1
17            int len2 = expandAroundCenter(s, i, i + 1);
18            
19            // Get the maximum length found from this center point
20            int current_max = std::max(len1, len2);
21            
22            // If it's longer than our previous record, update the boundaries
23            if (current_max > max_len) {
24                max_len = current_max;
25                // Calculate the true starting position of this substring
26                start = i - (current_max - 1) / 2;
27            }
28        }
29        
30        return s.substr(start, max_len);
31    }
32
33private:
34    int expandAroundCenter(const std::string& s, int left, int right) {
35        // Expand outwards as long as pointers are in bounds and characters match
36        while (left >= 0 && right < s.length() && s[left] == s[right]) {
37            left--;
38            right++;
39        }
40        // Returns the length of the valid palindromic substring
41        return right - left - 1;
42    }
43};