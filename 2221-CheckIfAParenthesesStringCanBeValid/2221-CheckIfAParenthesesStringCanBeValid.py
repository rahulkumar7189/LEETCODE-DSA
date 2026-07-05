# Last updated: 7/5/2026, 11:03:25 PM
class Solution(object):
    def canBeValid(self, s, locked):
        """
        :type s: str
        :type locked: str
        :rtype: bool
        """
        n = len(s)
        
        # If the length of s is odd, it can never be valid
        if n % 2 != 0:
            return False
        
        # Check from left to right
        open_count = 0
        close_count = 0
        
        for i in range(n):
            if locked[i] == '1':
                if s[i] == '(':
                    open_count += 1
                else:
                    close_count += 1
            else:
                # We can treat locked[i] as either '(' or ')'
                open_count += 1  # Assume we can use it as '('
            
            # If at any point close_count exceeds open_count, it's invalid
            if close_count > open_count:
                return False
        
        # Check from right to left
        open_count = 0
        close_count = 0
        
        for i in range(n - 1, -1, -1):
            if locked[i] == '1':
                if s[i] == ')':
                    close_count += 1
                else:
                    open_count += 1
            else:
                # We can treat locked[i] as either '(' or ')'
                close_count += 1  # Assume we can use it as ')'
            
            # If at any point open_count exceeds close_count, it's invalid
            if open_count > close_count:
                return False
        
        return True
        