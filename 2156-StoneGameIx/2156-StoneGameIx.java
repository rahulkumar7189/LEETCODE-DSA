// Last updated: 8/16/2026, 6:21:08 PM
class Solution {
    public boolean stoneGameIX(int[] stones) {
        int[] count = new int[3];
        
        // Count the frequencies of remainders
        for (int stone : stones) {
            count[stone % 3]++;
        }
        
        // If the number of 0s is even, Alice wins if both 1s and 2s are present.
        if (count[0] % 2 == 0) {
            return count[1] > 0 && count[2] > 0;
        } 
        // If the number of 0s is odd, Alice wins if the difference between 1s and 2s is greater than 2.
        else {
            return Math.abs(count[1] - count[2]) > 2;
        }
    }
}