// Last updated: 7/5/2026, 11:02:29 PM
import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] maximumMEX(int[] nums) {
        int n = nums.length;
        
        // Using n + 2 because the maximum possible MEX for an array of size N is N.
        // Elements greater than N + 1 don't affect the MEX calculation.
        int[] freq = new int[n + 2];
        for (int x : nums) {
            if (x < n + 2) {
                freq[x]++;
            }
        }
        
        // Find the initial MEX of the entire array
        int actual_mex = 0;
        while (freq[actual_mex] > 0) {
            actual_mex++;
        }
        
        int target_mex = actual_mex;
        int[] seen = new int[n + 2];
        int round = 1;
        int count = 0;
        
        List<Integer> resList = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            
            // 1. Remove the current element from the remaining suffix and update suffix MEX
            if (x < n + 2) {
                freq[x]--;
                // If a required number disappears, the suffix MEX drops to that number
                if (freq[x] == 0 && x < actual_mex) {
                    actual_mex = x;
                }
            }
            
            // 2. Track unique elements needed to reach our current target_mex
            if (x < target_mex && seen[x] != round) {
                seen[x] = round;
                count++;
            }
            
            // 3. If we have found all numbers from 0 to target_mex - 1, the prefix is complete
            if (count == target_mex) {
                resList.add(target_mex);
                
                // The new target is whatever the remaining suffix MEX is right now
                target_mex = actual_mex;
                
                // Advance the round to instantly "clear" the seen array in O(1) time
                round++;
                count = 0;
            }
        }
        
        // Convert the List to an int array for the final return
        int[] res = new int[resList.size()];
        for (int i = 0; i < resList.size(); i++) {
            res[i] = resList.get(i);
        }
        
        return res;
    }
}