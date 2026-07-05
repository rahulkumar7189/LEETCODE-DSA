# Last updated: 7/5/2026, 11:03:12 PM
class Solution(object):
    def findThePrefixCommonArray(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        n = len(A)
        freq = [0] * (n + 1)
        C = []
        common_count = 0
        
        for i in range(n):
            # Process the element from array A
            freq[A[i]] += 1
            if freq[A[i]] == 2:
                common_count += 1
                
            # Process the element from array B
            freq[B[i]] += 1
            if freq[B[i]] == 2:
                common_count += 1
                
            # Append the current common count to our result array C
            C.append(common_count)
            
        return C