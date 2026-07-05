# Last updated: 7/5/2026, 11:03:11 PM
class Solution(object):
    def vowelStrings(self, words, queries):
        """
        :type words: List[str]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        # Define the set of vowels
        vowels = {'a', 'e', 'i', 'o', 'u'}
        
        # Create a prefix sum array
        prefix_sum = [0] * (len(words) + 1)
        
        # Fill the prefix sum array
        for i in range(len(words)):
            # Check if the current word starts and ends with a vowel
            if words[i][0] in vowels and words[i][-1] in vowels:
                prefix_sum[i + 1] = prefix_sum[i] + 1
            else:
                prefix_sum[i + 1] = prefix_sum[i]
        
        # Prepare the result for each query
        result = []
        for li, ri in queries:
            # The number of valid strings in the range [li, ri]
            count = prefix_sum[ri + 1] - prefix_sum[li]
            result.append(count)
        
        return result