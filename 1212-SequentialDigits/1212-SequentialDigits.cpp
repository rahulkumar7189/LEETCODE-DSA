// Last updated: 7/14/2026, 2:32:29 PM
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> result;
        
        // The length of sequential digits can range from 2 to 9
        for (int length = 2; length <= 9; ++length) {
            // Slide a window of size 'length' across the digits string
            for (int i = 0; i <= 9 - length; ++i) {
                string sub = digits.substr(i, length);
                int num = stoi(sub);
                
                // If the number falls in the range, add it to our result
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        return result;
    }
};