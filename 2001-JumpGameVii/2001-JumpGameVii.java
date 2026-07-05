// Last updated: 7/5/2026, 11:03:30 PM
class Solution {
    public boolean canReach(String s, int minJump, int maxJump) {
        int n = s.length();
        // If the destination is not '0', it's impossible to reach
        if (s.charAt(n - 1) != '0') {
            return false;
        }

        // dp[i] will be true if index i is reachable
        boolean[] dp = new boolean[n];
        dp[0] = true; // Start position

        // activeReachable counts how many reachable ('true') indices 
        // currently sit inside the window [i - maxJump, i - minJump]
        int activeReachable = 0;

        for (int i = 1; i < n; i++) {
            // 1. Add the new element entering the window from the right side
            if (i >= minJump) {
                if (dp[i - minJump]) {
                    activeReachable++;
                }
            }

            // 2. Remove the old element exiting the window from the left side
            if (i > maxJump) {
                if (dp[i - maxJump - 1]) {
                    activeReachable--;
                }
            }

            // 3. If the current position is a valid landing spot ('0') 
            // and there is at least one reachable index in our window
            if (s.charAt(i) == '0' && activeReachable > 0) {
                dp[i] = true;
            }
        }

        return dp[n - 1];
    }
}