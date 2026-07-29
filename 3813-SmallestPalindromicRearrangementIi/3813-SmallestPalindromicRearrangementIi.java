// Last updated: 7/29/2026, 11:39:14 AM
class Solution {
    public String smallestPalindrome(String s, int k) {
        int n = s.length();
        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }
        
        int[] half = new int[26];
        char midChar = 0;
        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] % 2 != 0) {
                midChar = (char) ('a' + i);
            }
        }
        
        int N = n / 2; // Length of the half string
        
        // Precompute combinations (Pascal's Triangle) up to N to prevent repeated factorial calculation
        // We only cap it at 10^12 because k is up to 10^6
        long[][] C = new long[N + 1][];
        long LIMIT = (long) 1e12; 
        for (int i = 0; i <= N; i++) {
            C[i] = new long[i + 1];
            C[i][0] = 1;
            C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                if (C[i][j] > LIMIT) {
                    C[i][j] = LIMIT;
                }
            }
        }
        
        // Calculate the total number of permutations for the first half
        long totalWays = 1;
        int len = 0;
        for (int i = 0; i < 26; i++) {
            if (half[i] > 0) {
                len += half[i];
                long combo = C[len][half[i]];
                
                // Safe multiplication to prevent long overflow
                if (totalWays > LIMIT / combo) {
                    totalWays = LIMIT;
                } else {
                    totalWays *= combo;
                }
            }
        }
        
        // If k exceeds total possible unique permutations, return empty string
        if (k > totalWays) {
            return "";
        }
        
        StringBuilder sb = new StringBuilder();
        long currentK = k;
        
        // Construct the first half from left to right
        for (int i = 0; i < N; i++) {
            // Greedily place the lexicographically smallest possible character
            for (int c = 0; c < 26; c++) {
                if (half[c] > 0) {
                    half[c]--; // Temporarily place 'c' at the current position
                    
                    // Count how many combinations are possible for the rest of the string
                    long ways = 1;
                    int remLen = 0;
                    for (int j = 0; j < 26; j++) {
                        if (half[j] > 0) {
                            remLen += half[j];
                            long combo = C[remLen][half[j]];
                            if (ways > LIMIT / combo) {
                                ways = LIMIT;
                            } else {
                                ways *= combo;
                            }
                        }
                    }
                    
                    if (currentK <= ways) {
                        // The k-th permutation falls within this branch. Fix 'c' and move forward.
                        sb.append((char) ('a' + c));
                        break; 
                    } else {
                        // Skip this character and deduct its subtree combinations from k
                        currentK -= ways;
                        half[c]++; // Backtrack and try the next character
                    }
                }
            }
        }
        
        // Finalize the full palindrome
        String firstHalf = sb.toString();
        StringBuilder res = new StringBuilder(firstHalf);
        if (n % 2 != 0) {
            res.append(midChar); // Append middle character for odd length strings
        }
        res.append(new StringBuilder(firstHalf).reverse());
        
        return res.toString();
    }
}