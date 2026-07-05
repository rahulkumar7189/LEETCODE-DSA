// Last updated: 7/5/2026, 11:02:35 PM
import java.util.Arrays;

class Solution {
    // dp[idx][tight][leading][last][secLast][0] -> stores total waviness
    // dp[idx][tight][leading][last][secLast][1] -> stores total valid numbers formed from this state
    private Long[][][][][][] dp;
    private String numStr;

    public long totalWaviness(long num1, long num2) {
        return getWavinessForPrefix(num2) - getWavinessForPrefix(num1 - 1);
    }

    private long getWavinessForPrefix(long limit) {
        if (limit < 100) return 0;
        
        numStr = String.valueOf(limit);
        int n = numStr.length();
        
        // 6D array to track both [waviness, valid_count] at index 0 and 1
        dp = new Long[n][2][2][11][11][2];
        
        return countWavinessAndWays(0, 1, 1, 10, 10)[0];
    }

    // Returns a long[] where:
    // res[0] = total waviness from this state onwards
    // res[1] = number of valid numbers that can be formed from this state onwards
    private long[] countWavinessAndWays(int idx, int tight, int leading, int last, int secLast) {
        // Base Case: We successfully built a valid number!
        if (idx == numStr.length()) {
            return new long[]{0, 1}; // 0 waviness contributed here, but counts as 1 valid path
        }

        if (dp[idx][tight][leading][last][secLast][0] != null) {
            return new long[]{
                dp[idx][tight][leading][last][secLast][0],
                dp[idx][tight][leading][last][secLast][1]
            };
        }

        long totalWaviness = 0;
        long totalWays = 0;
        int limitDigit = tight == 1 ? numStr.charAt(idx) - '0' : 9;

        for (int d = 0; d <= limitDigit; d++) {
            int nextTight = (tight == 1 && d == limitDigit) ? 1 : 0;
            int nextLeading = (leading == 1 && d == 0) ? 1 : 0;

            if (nextLeading == 1) {
                // Still processing leading zeros
                long[] nextState = countWavinessAndWays(idx + 1, nextTight, 1, 10, 10);
                totalWaviness += nextState[0];
                totalWays += nextState[1];
            } else {
                // Placing a valid digit
                long[] nextState = countWavinessAndWays(idx + 1, nextTight, 0, d, last);
                long suffixWaviness = nextState[0];
                long suffixWays = nextState[1];

                long currentContribution = 0;
                // Check if 'last' forms a peak or valley
                if (leading == 0 && last != 10 && secLast != 10) {
                    if ((last > secLast && last > d) || (last < secLast && last < d)) {
                        currentContribution = 1;
                    }
                }

                // Total waviness from this branch = (local peak/valley * number of valid suffixes) + waviness deeper in the suffix
                totalWaviness += (currentContribution * suffixWays) + suffixWaviness;
                totalWays += suffixWays;
            }
        }

        dp[idx][tight][leading][last][secLast][0] = totalWaviness;
        dp[idx][tight][leading][last][secLast][1] = totalWays;

        return new long[]{totalWaviness, totalWays};
    }
}