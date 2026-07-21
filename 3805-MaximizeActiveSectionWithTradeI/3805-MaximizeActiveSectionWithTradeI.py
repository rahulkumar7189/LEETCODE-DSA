# Last updated: 7/22/2026, 1:23:53 AM
class Solution(object):
    def maxActiveSectionsAfterTrade(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Form augmented string t
        t = "1" + s + "1"
        
        # Group contiguous characters into blocks of (char, count)
        blocks = []
        i = 0
        n = len(t)
        while i < n:
            j = i
            while j < n and t[j] == t[i]:
                j += 1
            blocks.append((t[i], j - i))
            i = j
            
        max_gain = 0
        
        # An internal block of '1's surrounded by '0's appears as
        # ('0', len1), ('1', len_ones), ('0', len2) in the blocks array
        for idx in range(1, len(blocks) - 1):
            char, count = blocks[idx]
            if char == '1' and blocks[idx - 1][0] == '0' and blocks[idx + 1][0] == '0':
                gain = blocks[idx - 1][1] + blocks[idx + 1][1]
                max_gain = max(max_gain, gain)
                
        return s.count('1') + max_gain