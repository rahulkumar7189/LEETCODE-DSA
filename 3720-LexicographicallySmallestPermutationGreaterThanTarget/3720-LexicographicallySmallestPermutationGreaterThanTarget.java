// Last updated: 9/11/2026, 11:32:14 PM
class Solution {
    public String lexGreaterPermutation(String s, String target) {
        int n = s.length();
        int[] sCounts = new int[26];
        for (char c : s.toCharArray()) {
            sCounts[c - 'a']++;
        }

        // Find the maximum length of target's prefix that can be formed by s
        int[] currentCounts = new int[26];
        int maxMatch = 0;
        for (int i = 0; i < n; i++) {
            int idx = target.charAt(i) - 'a';
            if (currentCounts[idx] < sCounts[idx]) {
                currentCounts[idx]++;
                maxMatch++;
            } else {
                break;
            }
        }

        // Scan backwards from maxMatch to find the optimal deviation point
        for (int i = maxMatch; i >= 0; i--) {
            if (i == n) continue; // Cannot deviate beyond the string length
            
            // Count remaining characters available after matching target[0...i-1]
            int[] available = sCounts.clone();
            for (int j = 0; j < i; j++) {
                available[target.charAt(j) - 'a']--;
            }
            
            // Find the smallest available character strictly greater than target.charAt(i)
            int targetCharIdx = target.charAt(i) - 'a';
            int chooseIdx = -1;
            for (int c = targetCharIdx + 1; c < 26; c++) {
                if (available[c] > 0) {
                    chooseIdx = c;
                    break;
                }
            }
            
            // If a valid character is found, construct the smallest permutation
            if (chooseIdx != -1) {
                StringBuilder sb = new StringBuilder();
                sb.append(target, 0, i);
                sb.append((char) ('a' + chooseIdx));
                available[chooseIdx]--;
                
                // Append all remaining characters in sorted (ascending) order
                for (int c = 0; c < 26; c++) {
                    while (available[c] > 0) {
                        sb.append((char) ('a' + c));
                        available[c]--;
                    }
                }
                return sb.toString();
            }
        }
        
        return "";
    }
}
