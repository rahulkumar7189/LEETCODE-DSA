# Last updated: 7/5/2026, 11:02:56 PM
class Solution(object):
    def minimumOperations(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)  # Number of rows
        n = len(grid[0])  # Number of columns
        total_operations = 0
        
        # Iterate through each column
        for j in range(n):
            for i in range(1, m):
                # If the current element is not greater than the one above it
                if grid[i][j] <= grid[i - 1][j]:
                    # Calculate the number of operations needed
                    operations_needed = (grid[i - 1][j] - grid[i][j]) + 1
                    total_operations += operations_needed
                    # Update the current element to reflect the operations
                    grid[i][j] += operations_needed
        
        return total_operations