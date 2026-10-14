// Last updated: 10/14/2026, 9:12:01 PM
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // If the required sum exceeds the maximum possible sum of digits
        if (sum > 9LL * num) {
            return "";
        }
        
        string result(num, '0');
        
        for (int i = 0; i < num; ++i) {
            int d = min(9, sum);
            result[i] = d + '0';
            sum -= d;
            
            // Once the sum is exhausted, the rest of the string remains '0'
            if (sum == 0) {
                break;
            }
        }
        
        return result;
    }
};