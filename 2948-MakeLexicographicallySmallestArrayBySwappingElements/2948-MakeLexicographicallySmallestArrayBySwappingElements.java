// Last updated: 9/15/2026, 11:53:39 PM
import java.util.*;

class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int n = nums.length;
        int[][] paired = new int[n][2];
        
        // 1. Store value and original index
        for (int i = 0; i < n; i++) {
            paired[i][0] = nums[i];
            paired[i][1] = i;
        }
        
        // 2. Sort by value
        Arrays.sort(paired, (a, b) -> Integer.compare(a[0], b[0]));
        
        int[] result = new int[n];
        int i = 0;
        
        // 3. Group and rearrange components
        while (i < n) {
            int j = i + 1;
            // Find the boundary of the current connected component
            while (j < n && paired[j][0] - paired[j - 1][0] <= limit) {
                j++;
            }
            
            // Extract the original indices for this component
            int[] indices = new int[j - i];
            for (int k = i; k < j; k++) {
                indices[k - i] = paired[k][1];
            }
            
            // Sort original indices to fill them in ascending order
            Arrays.sort(indices);
            
            // Place sorted values into sorted indices
            for (int k = i; k < j; k++) {
                result[indices[k - i]] = paired[k][0];
            }
            
            // Move to the next component
            i = j;
        }
        
        return result;
    }
}
