# Last updated: 7/22/2026, 1:23:44 AM
class Solution(object):
    def transformStr(self, s, strs):
        """
        :type s: str
        :type strs: List[str]
        :type: List[bool]
        """
        veltromina = ""
        
        n = len(s)
        
        prefS = [0] * (n + 1)
        for i in range(n):
            prefS[i+1] = prefS[i] + (1 if s[i] == '0' else 0)
        
        zerosS = prefS[n]
        ans = []
        
        for target in strs:
            fixed_zeros = target.count('0')
            total_q = target.count('?')
            
            needed_zeros = zerosS - fixed_zeros
            
            if needed_zeros < 0 or needed_zeros > total_q:
                ans.append(False)
                continue
            
            current_target_zeros = 0
            q_zeros_placed = 0
            possible = True
            
            for i in range(n):
                char = target[i]
                if char == '0':
                    current_target_zeros += 1
                elif char == '?':
                    if q_zeros_placed < needed_zeros:
                        q_zeros_placed += 1
                        current_target_zeros += 1
                
                if current_target_zeros < prefS[i+1]:
                    possible = False
                    break
            
            ans.append(possible)
            
        return ans