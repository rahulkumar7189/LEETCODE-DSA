// Last updated: 7/5/2026, 11:03:06 PM
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int max_len = 1; // Any single element forms a valid subset of length 1

        // Handle the special case for 1
        if (freq.count(1)) {
            int count1 = freq[1];
            if (count1 % 2 == 0) {
                max_len = max(max_len, count1 - 1);
            } else {
                max_len = max(max_len, count1);
            }
        }

        // Check sequences for numbers > 1
        for (auto& [val, count] : freq) {
            if (val == 1) continue;

            long long current = val;
            int current_len = 0;

            // We can continue the chain as long as the current number has a frequency >= 2
            while (freq.count(current) && freq[current] >= 2) {
                current_len += 2;
                current = current * current; // Move to the next square
            }

            // Check if the peak element exists at least once
            if (freq.count(current) && freq[current] >= 1) {
                current_len += 1;
            } else {
                // If the peak doesn't exist, the last element we counted as '>= 2' 
                // must act as the peak itself, so we subtract 1 from the pairs.
                current_len -= 1;
            }

            max_len = max(max_len, current_len);
        }

        return max_len;
    }
};