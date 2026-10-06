// Last updated: 10/6/2026, 10:54:14 PM
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Base index for calculating valid substring length
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    // Current ')' has no match; set it as the new base index
                    st.push(i);
                } else {
                    // Length of the valid substring ending at i
                    maxLength = max(maxLength, i - st.top());
                }
            }
        }

        return maxLength;
    }
};