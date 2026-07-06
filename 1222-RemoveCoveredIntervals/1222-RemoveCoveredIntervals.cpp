// Last updated: 7/6/2026, 2:25:28 PM
#include <vector>
#include <algorithm>

class Solution {
public:
    int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
        // Sort: Ascending by start, Descending by end if starts are equal
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        int remainingCount = intervals.size();
        int max_end = 0;
        
        for (const auto& interval : intervals) {
            int end = interval[1];
            
            // If the current interval's end is covered by the max_end seen so far
            if (end <= max_end) {
                remainingCount--;
            } else {
                // Otherwise, update the boundary
                max_end = end;
            }
        }
        
        return remainingCount;
    }
};