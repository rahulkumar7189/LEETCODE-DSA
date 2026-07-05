// Last updated: 7/5/2026, 11:04:06 PM
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalsum = 0;
        int leftsum = 0;
        for (int num : nums) {
            totalsum += num;
        }
        for (int i = 0; i < nums.size(); i++) {
            int rightsum = totalsum - leftsum - nums[i];
            if (leftsum == rightsum) {
                return i; 
            }

            
            leftsum += nums[i];
        }

        return -1; 
    }
};