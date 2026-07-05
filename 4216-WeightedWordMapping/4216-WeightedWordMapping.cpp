// Last updated: 7/5/2026, 11:02:33 PM
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        
        for (const string& word : words) {
            long long total_weight = 0;
            
            // Step 1: Calculate total weight for the current word
            for (char c : word) {
                total_weight += weights[c - 'a'];
            }
            
            // Step 2 & 3: Find remainder and map to reverse alphabet
            int remainder = total_weight % 26;
            char mapped_char = 'z' - remainder;
            
            // Step 4: Append to result
            result += mapped_char;
        }
        
        return result;
    }
};