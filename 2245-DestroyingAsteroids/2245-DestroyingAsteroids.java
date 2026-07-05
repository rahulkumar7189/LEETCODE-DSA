// Last updated: 7/5/2026, 11:03:23 PM
import java.util.Arrays;

class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        // Sort asteroids to greedily consume the smallest ones first
        Arrays.sort(asteroids);
        
        // Use a long to prevent integer overflow as the planet gains mass
        long currentMass = mass;
        
        for (int asteroid : asteroids) {
            if (currentMass >= asteroid) {
                currentMass += asteroid;
            } else {
                // The planet doesn't have enough mass to destroy this asteroid
                return false; 
            }
        }
        
        // If we make it through the entire array, all asteroids were destroyed
        return true; 
    }
}