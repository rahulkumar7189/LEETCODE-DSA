// Last updated: 7/5/2026, 11:03:52 PM
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // Frequency array to store counts of 'a', 'b', 'l', 'n', 'o'
        // Index mapping: b=0, a=1, l=2, o=3, n=4
        vector<int> counts(5, 0);
        
        for (char c : text) {
            if (c == 'b') counts[0]++;
            else if (c == 'a') counts[1]++;
            else if (c == 'l') counts[2]++;
            else if (c == 'o') counts[3]++;
            else if (c == 'n') counts[4]++;
        }
        
        // 'l' and 'o' are needed twice per word, so divide their counts by 2
        counts[2] /= 2;
        counts[3] /= 2;
        
        // The answer is the minimum frequencies among all required characters
        int maxWords = counts[0];
        for (int i = 1; i < 5; i++) {
            maxWords = min(maxWords, counts[i]);
        }
        
        return maxWords;
    }
};