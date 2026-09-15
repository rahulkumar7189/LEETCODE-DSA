// Last updated: 9/15/2026, 11:57:26 PM
class Solution {
    public int distinctSubseqII(String s) {
        int MOD = 1_000_000_007;
        int[] count = new int[26];
        int total = 0; // Stores the sum of all distinct non-empty subsequences
        
        for (int i = 0; i < s.length(); i++) {
            int c = s.charAt(i) - 'a';
            int old_count = count[c];
            
            // New subsequences ending in character 'c'
            count[c] = (total + 1) % MOD;
            
            // Update the total distinct subsequences count
            total = (total - old_count + count[c]) % MOD;
            
            // Handle negative values resulting from modulo subtraction
            if (total < 0) {
                total += MOD;
            }
        }
        
        return total;
    }
}
