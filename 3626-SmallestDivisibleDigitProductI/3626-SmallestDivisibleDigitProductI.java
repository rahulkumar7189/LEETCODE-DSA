// Last updated: 8/6/2026, 3:31:08 PM
class Solution {
    public int smallestNumber(int n, int t) {
        int current = n;
        
        // Keep incrementing until we find a number satisfying the condition
        while (true) {
            if (getDigitProduct(current) % t == 0) {
                return current;
            }
            current++;
        }
    }
    
    // Helper method to calculate the product of digits of a given number
    private int getDigitProduct(int num) {
        int product = 1;
        while (num > 0) {
            product *= (num % 10);
            num /= 10;
        }
        return product;
    }
}