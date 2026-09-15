// Last updated: 9/15/2026, 11:55:07 PM
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        
        for (const string& pattern : patterns) {
            // std::string::npos is returned if the substring is not found
            if (word.find(pattern) != string::npos) {
                count++;
            }
        }
        
        return count;
    }
};