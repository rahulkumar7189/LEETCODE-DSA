// Last updated: 8/2/2026, 8:54:35 PM
class Solution {
    public int minimumPushes(String word) {
        // Count the frequency of each letter
        int[] freq = new int[26];
        for (char c : word.toCharArray()) {
            freq[c - 'a']++;
        }
        
        // Sort frequencies in ascending order
        java.util.Arrays.sort(freq);
        
        int totalPushes = 0;
        int position = 0;
        
        // Iterate from the highest frequency to the lowest
        for (int i = 25; i >= 0; i--) {
            if (freq[i] == 0) {
                break; // No more characters to process
            }
            
            // Calculate the cost multiplier based on the current position
            // Letters 0-7 cost 1, 8-15 cost 2, 16-23 cost 3, 24-25 cost 4
            int pushes = (position / 8) + 1;
            totalPushes += freq[i] * pushes;
            position++;
        }
        
        return totalPushes;
    }
}