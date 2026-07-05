// Last updated: 7/5/2026, 11:02:36 PM
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int validSubarraysCount = 0;

        // Iterate over all possible starting points of the subarray
        for (int i = 0; i < n; ++i) {
            int targetCount = 0;
            
            // Expand the subarray to the right
            for (int j = i; j < n; ++j) {
                if (nums[j] == target) {
                    targetCount++;
                }
                
                int currentLength = j - i + 1;
                
                // Condition for target to be the strict majority element
                if (targetCount * 2 > currentLength) {
                    validSubarraysCount++;
                }
            }
        }

        return validSubarraysCount;
                }
};