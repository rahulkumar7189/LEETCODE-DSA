// Last updated: 7/9/2026, 8:49:55 PM
#include <string>
#include <vector>
#include <numeric>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // Base case: if numRows is 1 or greater than/equal to string length,
        // the zigzag pattern is just the string itself.
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        // Create an array of strings for each row
        std::vector<std::string> rows(std::min(int(s.length()), numRows));
        
        int current_row = 0;
        bool going_down = false;

        for (char c : s) {
            rows[current_row] += c;
            
            // Reverse direction when we hit the top or bottom row
            if (current_row == 0 || current_row == numRows - 1) {
                going_down = !going_down;
            }
            
            // Move up or down based on current direction flag
            current_row += going_down ? 1 : -1;
        }

        // Combine all rows into a single string
        std::string result;
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};