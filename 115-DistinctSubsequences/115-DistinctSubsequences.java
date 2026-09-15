// Last updated: 9/15/2026, 11:58:16 PM
class Solution {
    public int numDistinct(String s, String t) {
        int m = s.length();
        int n = t.length();
        
        // dp[j] stores the number of distinct subsequences matching t[0...j-1]
        int[] dp = new int[n + 1];
        
        // Base case: An empty string t can always be formed in exactly 1 way
        dp[0] = 1;
        
        // Iterate through each character of string s
        for (int i = 1; i <= m; i++) {
            char sChar = s.charAt(i - 1);
            
            // Traverse backwards to avoid overwriting values from the current row
            for (int j = n; j >= 1; j--) {
                if (sChar == t.charAt(j - 1)) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        
        return dp[n];
    }
}
