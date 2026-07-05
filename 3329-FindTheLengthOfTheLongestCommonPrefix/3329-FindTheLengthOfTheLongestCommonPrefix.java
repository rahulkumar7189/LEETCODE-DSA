// Last updated: 7/5/2026, 11:03:05 PM
import java.util.HashSet;

class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        HashSet<Integer> prefixes = new HashSet<>();
        
        // Step 1: Add all possible prefixes of each number in arr1 to the HashSet
        for (int val : arr1) {
            while (val > 0) {
                prefixes.add(val);
                val /= 10; // Drop the last digit to get the next prefix
            }
        }
        
        int maxLength = 0;
        
        // Step 2: For each number in arr2, find its longest prefix present in the HashSet
        for (int val : arr2) {
            while (val > 0) {
                if (prefixes.contains(val)) {
                    // We found a common prefix!
                    // String.valueOf(val).length() gives the digit count.
                    maxLength = Math.max(maxLength, String.valueOf(val).length());
                    
                    // Break early: since we are shrinking the number from right to left,
                    // the first match we hit is guaranteed to be the longest for this specific number.
                    break;
                }
                val /= 10;
            }
        }
        
        return maxLength;
    }
}