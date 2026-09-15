// Last updated: 9/15/2026, 11:52:48 PM
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // Structure to represent the state of up to 4 intervals
    struct State {
        long long score = 0;
        int count = 0;
        int ids[4] = {0};

        // Overload < operator to define which state is "Worse".
        // A state is worse if it has a smaller score, OR 
        // if scores are equal but it is lexicographically larger.
        bool operator<(const State& b) const {
            if (score != b.score) {
                return score < b.score; 
            }
            
            // If scores are equal, we want lexicographically smaller array of IDs
            for (int i = 0; i < min(count, b.count); ++i) {
                if (ids[i] != b.ids[i]) {
                    return ids[i] > b.ids[i]; // Larger ID makes it a worse state
                }
            }
            // If all matched up to the minimum count, the one with more elements 
            // is lexicographically larger, so it is worse
            return count > b.count; 
        }
    };

    struct Interval {
        long long l, r, w;
        int id;
    };

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> arr(n);
        
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        // Sort by right boundary ascending. If tied, sort by ID.
        sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
            if (a.r != b.r) return a.r < b.r;
            return a.id < b.id; 
        });

        // dp[k][i] stores the best State choosing up to k intervals from arr[0...i]
        vector<vector<State>> dp(5, vector<State>(n));

        for (int i = 0; i < n; ++i) {
            // Find the last interval that ends before the current one starts (arr[j].r < arr[i].l)
            int low = 0, high = i - 1;
            int prev = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid].r < arr[i].l) {
                    prev = mid;
                    low = mid + 1; // Try finding a closer valid interval
                } else {
                    high = mid - 1;
                }
            }

            for (int k = 1; k <= 4; ++k) {
                // Option 1: Do not pick the current interval
                State skip = (i > 0) ? dp[k][i - 1] : State();

                // Option 2: Pick the current interval
                State take;
                if (prev != -1) {
                    take = dp[k - 1][prev];
                }
                
                take.score += arr[i].w;
                take.ids[take.count++] = arr[i].id;
                
                // Keep chosen original indices in sorted order for the state
                sort(take.ids, take.ids + take.count);

                // Update the state with the best out of skip vs take
                State best = skip;
                if (best < take) { // Check if 'take' is better than 'skip'
                    best = take;
                }

                dp[k][i] = best;
            }
        }

        // Reconstruct the best selected intervals from the final state
        vector<int> ans;
        for (int idx = 0; idx < dp[4][n - 1].count; ++idx) {
            ans.push_back(dp[4][n - 1].ids[idx]);
        }
        
        return ans;
    }
};