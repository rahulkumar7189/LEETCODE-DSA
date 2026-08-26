// Last updated: 8/26/2026, 11:42:40 PM
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            int ones_count = 0;
            string temp = "";
            
            for (int j = i; j < n; ++j) {
                temp += s[j];
                
                if (s[j] == '1') {
                    ones_count++;
                }
                
                // If we hit exactly k ones, check if it's the new best
                if (ones_count == k) {
                    if (ans == "" || temp.length() < ans.length() || 
                       (temp.length() == ans.length() && temp < ans)) {
                        ans = temp;
                    }
                } 
                // If we exceed k ones, no need to keep growing this substring
                else if (ones_count > k) {
                    break;
                }
            }
        }
        
        return ans;
    }
};