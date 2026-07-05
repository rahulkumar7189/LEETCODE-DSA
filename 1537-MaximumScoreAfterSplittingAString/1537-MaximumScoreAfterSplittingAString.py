# Last updated: 7/5/2026, 11:03:41 PM
class Solution(object):
    def maxScore(self, s):
        """
        :type s: str
        :rtype: int
        """
        total_ones = s.count('1')  # Count total number of '1's in the string
        max_score = 0
        left_zeros = 0  # Count of '0's in the left substring
        
        # Iterate through the string, stopping before the last character
        for i in range(len(s) - 1):
            if s[i] == '0':
                left_zeros += 1  # Increment count of '0's in the left substring
            else:
                total_ones -= 1  # Decrement count of '1's in the right substring
            
            # Calculate the score for the current split
            current_score = left_zeros + total_ones
            max_score = max(max_score, current_score)  # Update max score if current is higher
        
        return max_score