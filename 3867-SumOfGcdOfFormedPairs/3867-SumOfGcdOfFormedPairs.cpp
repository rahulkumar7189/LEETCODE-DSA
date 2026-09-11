// Last updated: 9/11/2026, 11:31:32 PM
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long gcdSum(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> prefixGcd(n);
        int mx = 0;
        
        // Step 1: Construct prefixGcd array
        for (int i = 0; i < n; ++i) {
            mx = std::max(mx, nums[i]);
            prefixGcd[i] = std::gcd(nums[i], mx);
        }
        
        // Step 2: Sort the prefixGcd array
        std::sort(prefixGcd.begin(), prefixGcd.end());
        
        // Step 3: Form pairs and compute the sum of their GCDs
        long long sum = 0;
        int left = 0;
        int right = n - 1;
        
        while (left < right) {
            sum += std::gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        
        return sum;
    }
};