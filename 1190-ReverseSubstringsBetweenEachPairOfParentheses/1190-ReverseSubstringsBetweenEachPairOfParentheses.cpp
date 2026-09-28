// Last updated: 9/28/2026, 11:01:21 PM
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        vector<int> st;
        
        // First pass: Map the indices of matching parentheses
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push_back(i);
            } else if (s[i] == ')') {
                int j = st.back();
                st.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }
        
        string res;
        int i = 0, direction = 1;
        
        // Second pass: Traverse the string building the result
        while (i < n) {
            if (s[i] == '(' || s[i] == ')') {
                // Teleport to the matching parenthesis and reverse direction
                i = pair[i];
                direction = -direction;
            } else {
                res += s[i];
            }
            i += direction;
        }
        
        return res;
    }
};