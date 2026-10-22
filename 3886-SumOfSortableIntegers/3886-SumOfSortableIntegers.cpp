// Last updated: 10/22/2026, 11:05:25 PM
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    bool isCyclicRotation(const vector<int>& nums, const vector<int>& s, int start, int k) {
        if (k == 1) return nums[start] == s[start];
        
        // Build LPS (Longest Prefix Suffix) array for the KMP pattern
        vector<int> lps(k, 0);
        int len = 0;
        int i = 1;
        while (i < k) {
            if (s[start + i] == s[start + len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        // KMP Search: Pattern is s[start...start+k-1], Text is nums[start...start+k-1] repeated twice
        int j = 0; 
        i = 0; 
        while (i < 2 * k - 1) {
            int text_val = nums[start + (i % k)];
            if (s[start + j] == text_val) {
                j++;
                i++;
            }
            if (j == k) {
                return true;
            } else if (i < 2 * k - 1 && s[start + j] != nums[start + (i % k)]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> s = nums;
        sort(s.begin(), s.end());
        
        long long total_sum = 0;
        
        // Iterate over all possible divisors of n
        for (int k = 1; k <= n; ++k) {
            if (n % k == 0) {
                bool valid = true;
                // Check each block of size k
                for (int i = 0; i < n; i += k) {
                    if (!isCyclicRotation(nums, s, i, k)) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    total_sum += k;
                }
            }
        }
        
        return total_sum;
    }
};