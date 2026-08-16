// Last updated: 8/16/2026, 6:19:24 PM
1class Solution {
2    public boolean stoneGameIX(int[] stones) {
3        int[] count = new int[3];
4        
5        // Count the frequencies of remainders
6        for (int stone : stones) {
7            count[stone % 3]++;
8        }
9        
10        // If the number of 0s is even, Alice wins if both 1s and 2s are present.
11        if (count[0] % 2 == 0) {
12            return count[1] > 0 && count[2] > 0;
13        } 
14        // If the number of 0s is odd, Alice wins if the difference between 1s and 2s is greater than 2.
15        else {
16            return Math.abs(count[1] - count[2]) > 2;
17        }
18    }
19}