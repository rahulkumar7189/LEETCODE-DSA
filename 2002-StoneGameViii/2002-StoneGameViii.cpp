// Last updated: 8/25/2026, 3:06:28 PM
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        
        // Calculate prefix sums inline to save space/time
        for (int i = 1; i < n; ++i) {
            stones[i] += stones[i - 1];
        }
        
        // Base case: if we take all stones, the next player has no moves left
        int dp = stones[n - 1];
        
        // Work backwards from the second to last element down to index 1
        for (int i = n - 2; i >= 1; --i) {
            dp = max(dp, stones[i] - dp);
        }
        
        return dp;
    }
};