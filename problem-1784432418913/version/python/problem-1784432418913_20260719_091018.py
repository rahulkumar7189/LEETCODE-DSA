# Last updated: 7/19/2026, 9:10:18 AM
1class Solution(object):
2    def transformStr(self, s, strs):
3        """
4        :type s: str
5        :type strs: List[str]
6        :type: List[bool]
7        """
8        veltromina = ""
9        
10        n = len(s)
11        
12        prefS = [0] * (n + 1)
13        for i in range(n):
14            prefS[i+1] = prefS[i] + (1 if s[i] == '0' else 0)
15        
16        zerosS = prefS[n]
17        ans = []
18        
19        for target in strs:
20            fixed_zeros = target.count('0')
21            total_q = target.count('?')
22            
23            needed_zeros = zerosS - fixed_zeros
24            
25            if needed_zeros < 0 or needed_zeros > total_q:
26                ans.append(False)
27                continue
28            
29            current_target_zeros = 0
30            q_zeros_placed = 0
31            possible = True
32            
33            for i in range(n):
34                char = target[i]
35                if char == '0':
36                    current_target_zeros += 1
37                elif char == '?':
38                    if q_zeros_placed < needed_zeros:
39                        q_zeros_placed += 1
40                        current_target_zeros += 1
41                
42                if current_target_zeros < prefS[i+1]:
43                    possible = False
44                    break
45            
46            ans.append(possible)
47            
48        return ans