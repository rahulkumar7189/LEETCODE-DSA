# Last updated: 7/5/2026, 11:03:43 PM
from collections import Counter

class Solution(object):
    def canConstruct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        # If the length of s is less than k, we cannot form k palindromes
        if len(s) < k:
            return False
        
        # Count the frequency of each character
        char_count = Counter(s)
        
        # Count how many characters have an odd frequency
        odd_count = sum(1 for count in char_count.values() if count % 2 != 0)
        
        # We can form k palindromes if the number of odd counts is less than or equal to k
        return odd_count <= k

# Example usage
solution = Solution()
print(solution.canConstruct("cr", 7))  # Output: False