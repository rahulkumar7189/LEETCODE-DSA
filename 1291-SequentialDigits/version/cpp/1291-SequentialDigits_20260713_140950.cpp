// Last updated: 7/13/2026, 2:09:50 PM
1class Solution {
2public:
3    vector<int> sequentialDigits(int low, int high) {
4        string digits = "123456789";
5        vector<int> result;
6        
7        // The length of sequential digits can range from 2 to 9
8        for (int length = 2; length <= 9; ++length) {
9            // Slide a window of size 'length' across the digits string
10            for (int i = 0; i <= 9 - length; ++i) {
11                string sub = digits.substr(i, length);
12                int num = stoi(sub);
13                
14                // If the number falls in the range, add it to our result
15                if (num >= low && num <= high) {
16                    result.push_back(num);
17                }
18            }
19        }
20        
21        return result;
22    }
23};