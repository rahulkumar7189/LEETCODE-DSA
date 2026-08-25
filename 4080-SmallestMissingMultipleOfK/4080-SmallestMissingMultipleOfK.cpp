// Last updated: 8/25/2026, 3:05:05 PM
class Solution {
public:
    int missingMultiple(std::vector<int>& nums, int k) {
        // Add all elements to a hash set for O(1) lookups
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        
        int multiple = k;
        
        // Keep incrementing by k until we find a multiple not in the set
        while (numSet.count(multiple)) {
            multiple += k;
        }
        
        return multiple;
    }
};