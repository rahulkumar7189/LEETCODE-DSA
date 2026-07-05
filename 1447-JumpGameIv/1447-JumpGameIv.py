# Last updated: 7/5/2026, 11:03:47 PM
from collections import defaultdict, deque

class Solution(object):
    def minJumps(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        n = len(arr)
        if n <= 1:
            return 0

        # Step 1: Map each value to all of its indices
        val_to_indices = defaultdict(list)
        for i, val in enumerate(arr):
            val_to_indices[val].append(i)

        # Step 2: Initialize BFS
        queue = deque([0])  # Stores the current indices to explore
        visited = {0}       # Tracks visited indices to prevent cycles
        steps = 0           # Tracks the number of jumps

        # Step 3: BFS loop
        while queue:
            # Process all nodes at the current level (current jump count)
            for _ in range(len(queue)):
                curr = queue.popleft()

                # If we've reached the last index, return the step count
                if curr == n - 1:
                    return steps

                # Gather all possible next moves
                next_moves = []
                
                # Move 1: Same value indices
                next_moves.extend(val_to_indices[arr[curr]])
                # OPTIMIZATION: Clear the list for this value so we don't process it again
                val_to_indices[arr[curr]] = [] 

                # Move 2: Next index (i + 1)
                if curr + 1 < n:
                    next_moves.append(curr + 1)
                
                # Move 3: Previous index (i - 1)
                if curr - 1 >= 0:
                    next_moves.append(curr - 1)

                # Add unvisited next moves to the queue
                for nxt in next_moves:
                    if nxt not in visited:
                        visited.add(nxt)
                        queue.append(nxt)

            # Increment step counter after finishing the current level
            steps += 1

        return -1