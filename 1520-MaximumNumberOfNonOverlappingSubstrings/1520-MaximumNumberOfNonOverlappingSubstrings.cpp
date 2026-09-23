// Last updated: 9/23/2026, 8:03:11 PM
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> left(26, -1);
        vector<int> right(26, -1);
        int n = s.length();
        
        // Step 1: Find the first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            if (left[s[i] - 'a'] == -1) left[s[i] - 'a'] = i;
            right[s[i] - 'a'] = i;
        }
        
        struct Interval {
            int l, r;
            // Sort primarily by end time (greedy choice).
            // If end times are tied, shorter length (larger start time) is better.
            bool operator<(const Interval& other) const {
                if (r == other.r) return l > other.l; 
                return r < other.r;
            }
        };
        
        vector<Interval> intervals;
        
        // Step 2: Validate the interval for each character's first occurrence
        for (int i = 0; i < 26; ++i) {
            if (left[i] != -1) {
                int l = left[i];
                int r = right[i];
                bool valid = true;
                
                // Expand the right bound to include all occurrences of inner characters
                for (int j = l; j <= r; ++j) {
                    // If an inner character starts before our current left bound, 
                    // this substring is not a valid independent minimum block.
                    if (left[s[j] - 'a'] < l) {
                        valid = false;
                        break;
                    }
                    r = max(r, right[s[j] - 'a']);
                }
                
                if (valid) {
                    intervals.push_back({l, r});
                }
            }
        }
        
        // Step 3: Greedily pick non-overlapping intervals
        sort(intervals.begin(), intervals.end());
        
        vector<string> res;
        int last_r = -1;
        for (const auto& inv : intervals) {
            if (inv.l > last_r) {
                res.push_back(s.substr(inv.l, inv.r - inv.l + 1));
                last_r = inv.r;
            }
        }
        
        return res;
    }
};