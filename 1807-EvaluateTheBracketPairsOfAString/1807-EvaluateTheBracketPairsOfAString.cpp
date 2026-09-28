// Last updated: 9/28/2026, 11:00:46 PM
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // Map to store knowledge for O(1) lookups
        unordered_map<string, string> dict;
        for (const auto& k : knowledge) {
            dict[k[0]] = k[1];
        }
        
        string ans = "";
        string key = "";
        bool inBracket = false;
        
        for (char c : s) {
            if (c == '(') {
                inBracket = true;
                key = ""; // Reset key for the new bracket pair
            } else if (c == ')') {
                inBracket = false;
                // Evaluate the key and append to answer
                if (dict.count(key)) {
                    ans += dict[key];
                } else {
                    ans += '?';
                }
            } else if (inBracket) {
                key += c; // Build the key
            } else {
                ans += c; // Append standard characters
            }
        }
        
        return ans;
    }
};