// Last updated: 7/5/2026, 11:02:37 PM
class Solution {
    public int totalWaviness(int num1, int num2) {
        int totalSum = 0;
        
        for (int i = num1; i <= num2; i++) {
            totalSum += calculateWaviness(i);
        }
        
        return totalSum;
    }
    
    private int calculateWaviness(int num) {
        // Any number with fewer than 3 digits has a waviness of 0
        if (num < 100) {
            return 0;
        }
        
        String s = Integer.toString(num);
        int waviness = 0;
        int len = s.length();
        
        // The first and last digits cannot be peaks or valleys, 
        // so we loop from index 1 to len - 2
        for (int i = 1; i < len - 1; i++) {
            char prev = s.charAt(i - 1);
            char curr = s.charAt(i);
            char next = s.charAt(i + 1);
            
            // Check for Peak
            if (curr > prev && curr > next) {
                waviness++;
            }
            // Check for Valley
            else if (curr < prev && curr < next) {
                waviness++;
            }
        }
        
        return waviness;
    }
}