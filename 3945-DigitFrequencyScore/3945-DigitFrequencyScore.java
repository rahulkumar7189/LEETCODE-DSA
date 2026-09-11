// Last updated: 9/11/2026, 11:30:53 PM
class Solution {
    public int digitFrequencyScore(int n) {
        int score = 0;
        
        while (n > 0) {
            // Extract the last digit and add it to the score
            score += n % 10;
            // Remove the last digit from n
            n /= 10;
        }
        
        return score;
    }
}