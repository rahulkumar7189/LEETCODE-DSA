# Last updated: 7/22/2026, 1:24:29 AM
class Solution(object):
    def smallestSubsequence(self, s):
        """
        :type s: str
        :rtype: str
        """
        # Step 1: Count the frequency of each character
        remain_count = {}
        for char in s:
            remain_count[char] = remain_count.get(char, 0) + 1
            
        stack = []
        seen = set()
        
        # Step 2: Iterate through the string
        for char in s:
            # If the character is already in our result, we skip it
            if char not in seen:
                # Maintain the monotonic increasing order if possible
                while stack and stack[-1] > char and remain_count[stack[-1]] > 0:
                    removed_char = stack.pop()
                    seen.remove(removed_char)
                
                # Add the current character to stack and marked as seen
                stack.append(char)
                seen.add(char)
                
            # Decrement the remaining count for the character
            remain_count[char] -= 1
            
        return "".join(stack)