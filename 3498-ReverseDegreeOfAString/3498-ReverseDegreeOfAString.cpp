// Last updated: 9/23/2026, 8:01:49 PM
class Solution {
public:
    int reverseDegree(string s) {
        int total_degree = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // Calculate the 1-based index in the reversed alphabet
            int reversed_alphabet_index = 'z' - s[i] + 1;
            
            // Calculate the 1-based index in the string
            int string_position = i + 1;
            
            // Add the product to the total sum
            total_degree += reversed_alphabet_index * string_position;
        }
        
        return total_degree;
    }
};