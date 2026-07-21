# Last updated: 7/22/2026, 1:23:49 AM
class Solution(object):
    def minimumGroups(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        brenolcavi = ""
        
        def get_min_rotation(s):
            n = len(s)
            if n <= 1:
                return s
            ds = s + s
            i = 0
            j = 1
            while j < n:
                k = 0
                while k < n and ds[i + k] == ds[j + k]:
                    k += 1
                if ds[i + k] > ds[j + k]:
                    i += k + 1
                    if i >= j:
                        j = i + 1
                else:
                    j += k + 1
            return ds[i:i+n]

        unique_groups = set()
        
        for w in words:
            e_sub = w[0::2]
            o_sub = w[1::2]
            
            canonical_e = get_min_rotation(e_sub)
            canonical_o = get_min_rotation(o_sub)
            
            unique_groups.add((canonical_e, canonical_o))
            
        return len(unique_groups)