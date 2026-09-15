// Last updated: 9/15/2026, 11:57:38 PM
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> v1, v2;
        
        // Step 1: Collect coordinates of all 1s in both images
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) v1.push_back({i, j});
                if (img2[i][j] == 1) v2.push_back({i, j});
            }
        }
        
        unordered_map<int, int> shift_counts;
        int max_overlap = 0;
        
        // Step 2 & 3: Calculate translation vectors and count their frequencies
        for (auto& p1 : v1) {
            for (auto& p2 : v2) {
                int dx = p2.first - p1.first;
                int dy = p2.second - p1.second;
                
                // Convert the 2D shift into a unique 1D integer key for the hash map
                // Since n <= 30, the shifts dx and dy will be in the range [-29, 29].
                // We add 30 to make them strictly positive integers [1, 59].
                int key = (dx + 30) * 100 + (dy + 30);
                
                shift_counts[key]++;
                max_overlap = max(max_overlap, shift_counts[key]);
            }
        }
        
        // Step 4: Return the maximum overlap found
        return max_overlap;
    }
};