# Last updated: 7/19/2026, 5:19:58 PM
1class Solution(object):
2    def smallestSubsequence(self, s):
3        """
4        :type s: str
5        :rtype: str
6        """
7        # Step 1: Count the frequency of each character
8        remain_count = {}
9        for char in s:
10            remain_count[char] = remain_count.get(char, 0) + 1
11            
12        stack = []
13        seen = set()
14        
15        # Step 2: Iterate through the string
16        for char in s:
17            # If the character is already in our result, we skip it
18            if char not in seen:
19                # Maintain the monotonic increasing order if possible
20                while stack and stack[-1] > char and remain_count[stack[-1]] > 0:
21                    removed_char = stack.pop()
22                    seen.remove(removed_char)
23                
24                # Add the current character to stack and marked as seen
25                stack.append(char)
26                seen.add(char)
27                
28            # Decrement the remaining count for the character
29            remain_count[char] -= 1
30            
31        return "".join(stack)