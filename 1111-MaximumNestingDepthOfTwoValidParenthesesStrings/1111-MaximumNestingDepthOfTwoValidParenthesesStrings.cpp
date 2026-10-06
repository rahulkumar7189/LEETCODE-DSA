// Last updated: 10/6/2026, 10:53:06 PM
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.length());
        for (int i = 0; i < seq.length(); ++i) {
            if (seq[i] == '(') {
                ans[i] = i % 2;
            } else {
                ans[i] = 1 - (i % 2);
            }
        }
        return ans;
    }
};