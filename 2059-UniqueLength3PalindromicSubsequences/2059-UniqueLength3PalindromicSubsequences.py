# Last updated: 7/5/2026, 11:03:29 PM
class Solution(object):
    def countPalindromicSubsequence(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Dictionary to store the first and last occurrence of each character
        char_indices = {}
        
        for i, char in enumerate(s):
            if char not in char_indices:
                char_indices[char] = [i, i]  # [first_index, last_index]
            else:
                char_indices[char][1] = i  # Update last_index
        
        unique_palindromes = set()
        
        # Iterate through the characters and their indices
        for char, (first_index, last_index) in char_indices.items():
            if first_index < last_index:  # Ensure we have at least two occurrences
                # Find all characters that can be in the middle
                middle_chars = set(s[first_index + 1:last_index])
                for middle_char in middle_chars:
                    unique_palindromes.add(char + middle_char + char)
        
        return len(unique_palindromes)
