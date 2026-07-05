// Last updated: 7/5/2026, 11:03:09 PM
class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] res = new int[n];
        int[] freq = new int[n + 1]; 
        int common = 0;
        
        for (int i = 0; i < n; i++) {
            if (++freq[A[i]] == 2) common++;
            if (++freq[B[i]] == 2) common++;
            
            res[i] = common;
        }
        
        return res;
    }
}