// Last updated: 8/6/2026, 3:30:34 PM
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        int min = nums[0];
        int max = nums[0];
        
        Set<Integer> set = new HashSet<>();
        
        for (int num : nums) {
            if (num < min) min = num;
            if (num > max) max = num;
            set.add(num);
        }
        
        List<Integer> missing = new ArrayList<>();
        
        for (int i = min; i <= max; i++) {
            if (!set.contains(i)) {
                missing.add(i);
            }
        }
        
        return missing;
    }
}