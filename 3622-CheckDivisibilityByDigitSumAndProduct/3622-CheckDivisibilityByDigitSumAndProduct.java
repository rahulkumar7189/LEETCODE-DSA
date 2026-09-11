// Last updated: 9/11/2026, 11:32:53 PM
class Solution {
    public boolean checkDivisibility(int n) {
        int temp = n;
        int digitSum = 0;
        int digitProduct = 1;
        
        // Extract each digit and calculate sum and product
        while (temp > 0) {
            int digit = temp % 10;
            digitSum += digit;
            digitProduct *= digit;
            temp /= 10;
        }
        
        // Check if n is divisible by (digitSum + digitProduct)
        return n % (digitSum + digitProduct) == 0;
    }
}
