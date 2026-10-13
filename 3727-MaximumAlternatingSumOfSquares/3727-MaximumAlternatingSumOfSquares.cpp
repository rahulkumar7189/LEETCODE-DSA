// Last updated: 10/13/2026, 11:50:06 PM
#include <vector>
#include <algorithm>

class Solution {
public:
    long long maxAlternatingSum(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<long long> squares(n);
        
        // Convert all elements to their squares
        for (int i = 0; i < n; ++i) {
            squares[i] = (long long)nums[i] * nums[i];
        }
        
        // Sort descending to easily grab the largest elements
        std::sort(squares.rbegin(), squares.rend());
        
        long long max_score = 0;
        int positive_count = (n + 1) / 2; // Equivalent to ceil(n / 2.0)
        
        // Add the largest squares, subtract the smallest squares
        for (int i = 0; i < n; ++i) {
            if (i < positive_count) {
                max_score += squares[i];
            } else {
                max_score -= squares[i];
            }
        }
        
        return max_score;
    }
};