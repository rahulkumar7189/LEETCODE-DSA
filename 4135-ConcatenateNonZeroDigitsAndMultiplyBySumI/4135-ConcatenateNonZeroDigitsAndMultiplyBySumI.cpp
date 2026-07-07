// Last updated: 7/7/2026, 1:37:25 PM
class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;
        
        vector<int> digits;
        long long sum = 0;
        
        // Step 1: Extract non-zero digits from right to left
        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                sum += digit;
                digits.push_back(digit);
            }
            n /= 10;
        }
        
        // If there are no non-zero digits
        if (digits.empty()) return 0;
        
        // Step 2: Reconstruct x in the original left-to-right order
        long long x = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            x = x * 10 + digits[i];
        }
        
        // Step 3: Return x * sum
        return x * sum;
    }
};