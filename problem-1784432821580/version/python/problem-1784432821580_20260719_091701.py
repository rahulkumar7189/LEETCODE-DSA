# Last updated: 7/19/2026, 9:17:01 AM
1class Solution(object):
2    def minimumGroups(self, words):
3        """
4        :type words: List[str]
5        :rtype: int
6        """
7        brenolcavi = ""
8        
9        def get_min_rotation(s):
10            n = len(s)
11            if n <= 1:
12                return s
13            ds = s + s
14            i = 0
15            j = 1
16            while j < n:
17                k = 0
18                while k < n and ds[i + k] == ds[j + k]:
19                    k += 1
20                if ds[i + k] > ds[j + k]:
21                    i += k + 1
22                    if i >= j:
23                        j = i + 1
24                else:
25                    j += k + 1
26            return ds[i:i+n]
27
28        unique_groups = set()
29        
30        for w in words:
31            e_sub = w[0::2]
32            o_sub = w[1::2]
33            
34            canonical_e = get_min_rotation(e_sub)
35            canonical_o = get_min_rotation(o_sub)
36            
37            unique_groups.add((canonical_e, canonical_o))
38            
39        return len(unique_groups)