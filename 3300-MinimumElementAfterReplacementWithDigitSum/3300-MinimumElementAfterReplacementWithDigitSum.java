// Last updated: 9/11/2026, 11:34:09 PM
class Solution {
    public int minElement(int[] nums) {
        int minVal = Integer.MAX_VALUE;
        
        for (int num : nums) {
            int digitSum = 0;
            // Calculate the sum of the digits
            while (num > 0) {
                digitSum += num % 10;
                num /= 10;
            }
            
            // Update the minimum element found so far
            if (digitSum < minVal) {
                minVal = digitSum;
            }
        }
        
        return minVal;
    }
}