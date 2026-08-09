// Last updated: 8/9/2026, 7:08:09 PM
/*
 * Approach: Top-Down Dynamic Programming (Minimax)
 * This solution uses DP with memoization to find the optimal strategy. It precomputes a suffixSum array to easily calculate the total remaining stones in O(1) time.
 * For each state (i, m), it tries all possible moves X (from 1 to 2M). It calculates the current player's maximum stones by taking the total remaining stones from index i and subtracting the maximum stones the opponent can get from the next state (suffixSum[i] - dfs(...)).
 * 
 * Time Complexity: O(N 
 * 3
 *  ) — There are O(N 
 * 2
 *  ) states in the memo array (where N is the number of piles), and for each state, the loop runs up to 2M times (worst case O(N)).
 * 
 * Space Complexity: O(N 
 * 2
 *  ) — Required for the 2D memo array, plus O(N) for the recursion stack and suffixSum array.
*/

1class Solution {
2    public int stoneGameII(int[] piles) {
3        int n = piles.length;
4        if (n == 0) return 0;
5        
6        // memo[i][m] stores the maximum stones a player can get starting at index i with given M
7        int[][] memo = new int[n][n + 1];
8        
9        // suffixSum[i] stores the sum of stones from pile i to the end
10        int[] suffixSum = new int[n];
11        suffixSum[n - 1] = piles[n - 1];
12        for (int i = n - 2; i >= 0; i--) {
13            suffixSum[i] = suffixSum[i + 1] + piles[i];
14        }
15        
16        return dfs(0, 1, piles, suffixSum, memo);
17    }
18    
19    private int dfs(int i, int m, int[] piles, int[] suffixSum, int[][] memo) {
20        // If all piles are taken
21        if (i == piles.length) {
22            return 0;
23        }
24        
25        // If the current player can take all the remaining piles
26        if (i + 2 * m >= piles.length) {
27            return suffixSum[i];
28        }
29        
30        // Return precalculated result if it exists
31        if (memo[i][m] != 0) {
32            return memo[i][m];
33        }
34        
35        int maxStones = 0;
36        
37        // Try all possible moves: take X piles where 1 <= X <= 2M
38        for (int x = 1; x <= 2 * m; x++) {
39            // Stones current player gets = Total remaining stones - Max stones opponent can get
40            int currentStones = suffixSum[i] - dfs(i + x, Math.max(m, x), piles, suffixSum, memo);
41            maxStones = Math.max(maxStones, currentStones);
42        }
43        
44        // Store the result in memoization table and return
45        memo[i][m] = maxStones;
46        return maxStones;
47    }
48}