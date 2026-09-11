// Last updated: 9/11/2026, 11:31:28 PM
class Solution {
public:
    int countCommas(int n) {
        if (n < 1000) {
            return 0;
        }
        return n - 999;
    }
};