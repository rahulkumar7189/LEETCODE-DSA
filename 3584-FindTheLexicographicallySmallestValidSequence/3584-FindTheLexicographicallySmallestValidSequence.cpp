// Last updated: 8/16/2026, 6:20:28 PM
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> ans(m);
        
        // last[j] stores the largest index in word1 that can match word2[j...] perfectly
        vector<int> last(m, -1);
        int i = n - 1;
        int j = m - 1;
        
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }
        
        bool canSkip = true;
        j = 0;
        
        // Greedily match from left to right
        for (i = 0; i < n; ++i) {
            if (j == m) break;
            
            if (word1[i] == word2[j]) {
                ans[j++] = i;
            } 
            // If characters mismatch, try using the single allowed modification
            else if (canSkip && (j == m - 1 || i < last[j + 1])) {
                canSkip = false; // Use up the allowed edit
                ans[j++] = i;
            }
        }
        
        // If we successfully matched all characters of word2, return the sequence
        return (j == m) ? ans : vector<int>();
    }
};
