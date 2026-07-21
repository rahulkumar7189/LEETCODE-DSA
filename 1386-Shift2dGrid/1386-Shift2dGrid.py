# Last updated: 7/22/2026, 1:24:22 AM
class Solution(object):
    def shiftGrid(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        m, n = len(grid), len(grid[0])
        total = m * n
        
        # Optimize k to avoid unnecessary full grid rotations
        k = k % total
        
        # Initialize the result matrix with zeros
        res = [[0] * n for _ in range(m)]
        
        for r in range(m):
            for c in range(n):
                # Calculate 1D index
                flat_index = r * n + c
                
                # Calculate new 1D index after k shifts
                new_flat_index = (flat_index + k) % total
                
                # Map back to 2D coordinates in result grid
                new_r = new_flat_index // n
                new_c = new_flat_index % n
                
                res[new_r][new_c] = grid[r][c]
                
        return res