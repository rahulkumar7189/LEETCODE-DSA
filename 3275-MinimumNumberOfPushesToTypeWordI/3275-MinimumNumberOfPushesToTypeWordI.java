// Last updated: 7/30/2026, 2:50:21 PM
class Solution {
    public int minimumPushes(String word) {
        int n = word.length();
        int pushes = 0;
        
        // Loop through the length of the word and calculate cost
        for (int i = 0; i < n; i++) {
            // (i / 8) + 1 gives the cost multiplier: 
            // 1 for the first 8, 2 for the next 8, etc.
            pushes += (i / 8) + 1;
        }
        
        return pushes;
    }
}