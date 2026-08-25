// Last updated: 8/25/2026, 3:05:24 PM
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
