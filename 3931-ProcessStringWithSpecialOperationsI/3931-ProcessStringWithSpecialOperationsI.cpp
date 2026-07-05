// Last updated: 7/5/2026, 11:02:48 PM
class Solution {
public:
    string processStr(string s) {
        string result = "";
        
        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                result.push_back(ch);
            } 
            else if (ch == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } 
            else if (ch == '#') {
                result += result;
            } 
            else if (ch == '%') {
                std::reverse(result.begin(), result.end());
            }
        }
        
        return result;
    }
};