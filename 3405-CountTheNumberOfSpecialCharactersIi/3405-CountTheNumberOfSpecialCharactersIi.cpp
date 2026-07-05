// Last updated: 7/5/2026, 11:03:02 PM
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int numberOfSpecialChars(std::string word) {
        std::vector<int> lastLower(26, -1);
        std::vector<int> firstUpper(26, -1);

        // Record the last occurrence of lowercase and first occurrence of uppercase
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (std::islower(c)) {
                lastLower[c - 'a'] = i;
            } else {
                int upperIdx = c - 'A';
                if (firstUpper[upperIdx] == -1) {
                    firstUpper[upperIdx] = i;
                }
            }
        }

        int specialCount = 0;
        for (int i = 0; i < 26; ++i) {
            // Check if both lowercase and uppercase exist, 
            // and if every lowercase appears before the first uppercase
            if (lastLower[i] != -1 && firstUpper[i] != -1) {
                if (lastLower[i] < firstUpper[i]) {
                    specialCount++;
                }
            }
        }

        return specialCount;
    }
};
