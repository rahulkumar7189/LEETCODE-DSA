// Last updated: 9/28/2026, 10:59:25 PM
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            int temp = nums[i];
            
            // Calculate the sum of digits
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            
            // Return the first index that matches the condition
            if (sum == i) {
                return i;
            }
        }
        
        // If no such index exists, return -1
        return -1;
    }
};