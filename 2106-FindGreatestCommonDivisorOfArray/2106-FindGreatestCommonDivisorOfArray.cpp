// Last updated: 7/18/2026, 2:52:17 PM
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int findGCD(std::vector<int>& nums) {
        // Find the minimum and maximum elements in the array
        auto [mn, mx] = std::minmax_element(nums.begin(), nums.end());
        
        // Return the greatest common divisor of the two elements
        return std::gcd(*mn, *mx);
    }
};