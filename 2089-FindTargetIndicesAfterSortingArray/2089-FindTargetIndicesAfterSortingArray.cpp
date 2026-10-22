// Last updated: 10/22/2026, 11:07:54 PM
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lessCount = 0;
        int equalCount = 0;
        
        // Count numbers strictly less than the target and equal to the target
        for (int num : nums) {
            if (num < target) {
                lessCount++;
            } else if (num == target) {
                equalCount++;
            }
        }
        
        // The starting index in a sorted array would be exactly `lessCount`
        vector<int> result;
        for (int i = 0; i < equalCount; i++) {
            result.push_back(lessCount + i);
        }
        
        return result;
    }
};