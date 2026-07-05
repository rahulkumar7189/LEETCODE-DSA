// Last updated: 7/5/2026, 11:03:10 PM
class Solution {
    public int[] leftRightDifference(int[] nums) {
        int n = nums.length;
        int[] answer = new int[n];
        
        // Calculate the total sum of the array
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int leftSum = 0;
        for (int i = 0; i < n; i++) {
            // rightSum for index i is the remaining total sum minus the current element
            totalSum -= nums[i]; 
            int rightSum = totalSum;
            
            // Store the absolute difference
            answer[i] = Math.abs(leftSum - rightSum);
            
            // Update leftSum for the next index
            leftSum += nums[i];
        }
        
        return answer;
    }
}