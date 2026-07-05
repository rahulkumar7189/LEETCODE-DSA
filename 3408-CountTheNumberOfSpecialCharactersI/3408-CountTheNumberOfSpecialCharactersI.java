// Last updated: 7/5/2026, 11:03:01 PM
class Solution {
    public int numberOfSpecialChars(String word) {
        boolean[] lower = new boolean[26];
        boolean[] upper = new boolean[26];
        
        // Record the presence of each character
        for (char c : word.toCharArray()) {
            if (c >= 'a' && c <= 'z') {
                lower[c - 'a'] = true;
            } else if (c >= 'A' && c <= 'Z') {
                upper[c - 'A'] = true;
            }
        }
        
        int specialCount = 0;
        
        // Count characters that appear in both lowercase and uppercase
        for (int i = 0; i < 26; i++) {
            if (lower[i] && upper[i]) {
                specialCount++;
            }
        }
        
        return specialCount;
    }
}