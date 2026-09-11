// Last updated: 9/11/2026, 11:33:00 PM
import java.util.*;

public class Solution {
    public int minMoves(String[] classroom, int energy) {
        int m = classroom.length;
        int n = classroom[0].length();
        
        int startX = -1, startY = -1;
        int litterCount = 0;
        int[][] litterId = new int[m][n];
        for (int i = 0; i < m; i++) {
            Arrays.fill(litterId[i], -1);
        }
        
        // Find the start position and label each litter cell with a unique ID
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = classroom[i].charAt(j);
                if (c == 'S') {
                    startX = i;
                    startY = j;
                } else if (c == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }
        
        int targetMask = (1 << litterCount) - 1;
        
        // 3D array to store the maximum remaining energy for a given (x, y, mask)
        int[][][] bestEnergy = new int[m][n][1 << litterCount];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                Arrays.fill(bestEnergy[i][j], -1);
            }
        }
        
        // Queue stores states as array: {x, y, mask, current_energy}
        Queue<int[]> queue = new LinkedList<>();
        
        // Initialize starting state
        int startMask = 0;
        if (classroom[startX].charAt(startY) == 'L') {
            startMask |= (1 << litterId[startX][startY]);
        }
        
        queue.offer(new int[]{startX, startY, startMask, energy});
        bestEnergy[startX][startY][startMask] = energy;
        
        int steps = 0;
        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] curr = queue.poll();
                int x = curr[0];
                int y = curr[1];
                int mask = curr[2];
                int currEnergy = curr[3];
                
                // If all litter items are collected, return the current number of steps
                if (mask == targetMask) {
                    return steps;
                }
                
                // If energy is 0 and we are not on a reset tile, we cannot move further
                if (currEnergy == 0 && classroom[x].charAt(y) != 'R') {
                    continue;
                }
                
                for (int[] dir : dirs) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    
                    // Check grid boundaries and obstacles
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || classroom[nx].charAt(ny) == 'X') {
                        continue;
                    }
                    
                    int nextEnergy = currEnergy - 1;
                    if (nextEnergy < 0) {
                        continue;
                    }
                    
                    char nextCell = classroom[nx].charAt(ny);
                    int nextMask = mask;
                    
                    // Collect litter if available
                    if (nextCell == 'L') {
                        nextMask |= (1 << litterId[nx][ny]);
                    }
                    
                    // Restore energy if it's a reset area
                    if (nextCell == 'R') {
                        nextEnergy = energy;
                    }
                    
                    // Only traverse if this path offers strictly more energy than seen before
                    if (nextEnergy > bestEnergy[nx][ny][nextMask]) {
                        bestEnergy[nx][ny][nextMask] = nextEnergy;
                        queue.offer(new int[]{nx, ny, nextMask, nextEnergy});
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
}
