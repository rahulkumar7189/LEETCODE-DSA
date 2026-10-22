// Last updated: 10/22/2026, 11:05:34 PM
class Solution {
    public int minOperations(String s) {
        int n = s.length();
        
        // Case 0: Check if already sorted
        boolean isSorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (s.charAt(i) > s.charAt(i + 1)) {
                isSorted = false;
                break;
            }
        }
        if (isSorted) return 0;
        
        // Case -1: Length 2 and not sorted
        if (n == 2) return -1;
        
        // Find the global minimum and maximum characters
        char mn = 'z';
        char mx = 'a';
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c < mn) mn = c;
            if (c > mx) mx = c;
        }
        
        // Case 1: mn at the beginning or mx at the end
        if (s.charAt(0) == mn || s.charAt(n - 1) == mx) {
            return 1;
        }
        
        // Case 2: mn exists in a proper prefix OR mx exists in a proper suffix
        boolean mnInPrefix = false;
        for (int i = 0; i < n - 1; i++) {
            if (s.charAt(i) == mn) {
                mnInPrefix = true;
                break;
            }
        }
        
        boolean mxInSuffix = false;
        for (int i = 1; i < n; i++) {
            if (s.charAt(i) == mx) {
                mxInSuffix = true;
                break;
            }
        }
        
        if (mnInPrefix || mxInSuffix) {
            return 2;
        }
        
        // Case 3: mn is only at the end and mx is only at the beginning
        return 3;
    }
}
