# Last updated: 7/5/2026, 11:03:17 PM
class Solution(object):
    def waysToSplitArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        total_sum = sum(nums)  # Calculate the total sum of the array
        left_sum = 0  # Initialize the left sum
        valid_splits = 0  # Initialize the count of valid splits
        
        # Iterate through the array, stopping before the last element
        for i in range(len(nums) - 1):
            left_sum += nums[i]  # Update the left sum
            right_sum = total_sum - left_sum  # Calculate the right sum
            
            # Check if the current split is valid
            if left_sum >= right_sum:
                valid_splits += 1  # Increment the count of valid splits
        
        return valid_splits  # Return the total count of valid splits