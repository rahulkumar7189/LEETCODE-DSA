// Last updated: 9/11/2026, 11:31:03 PM
class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        
        int startColor = (start[0] + start[1]) % 2;
        int targetColor = (target[0] + target[1]) % 2;
        
        return startColor == targetColor;
    }
};