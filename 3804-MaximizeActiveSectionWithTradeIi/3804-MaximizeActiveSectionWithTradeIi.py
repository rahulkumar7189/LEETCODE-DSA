# Last updated: 7/22/2026, 2:02:21 PM
import bisect

class Solution(object):
    def maxActiveSectionsAfterTrade(self, s, queries):
        n = len(s)
        tot_ones = s.count('1')
        
        # 1. Parse string into alternating 0 and 1 segments
        seg_val = []
        seg_start = []
        seg_end = []
        
        i = 0
        while i < n:
            j = i
            while j < n and s[j] == s[i]:
                j += 1
            seg_val.append(int(s[i]))
            seg_start.append(i)
            seg_end.append(j - 1)
            i = j
            
        num_segs = len(seg_val)
        
        # If there are no zeros, no trades can increase active sections
        if all(v == 1 for v in seg_val):
            return [tot_ones] * len(queries)
            
        # 2. Build precomputed answers (potential net gains) for each segment
        ans = [0] * num_segs
        for idx in range(num_segs):
            if seg_val[idx] == 1:
                left_len = 0
                if idx > 0:
                    left_len = seg_end[idx-1] - seg_start[idx-1] + 1
                right_len = 0
                if idx < num_segs - 1:
                    right_len = seg_end[idx+1] - seg_start[idx+1] + 1
                ans[idx] = left_len + right_len
                
        # 3. Build Sparse Table for O(1) Range Maximum Queries
        log2 = [0] * (num_segs + 1)
        for idx in range(2, num_segs + 1):
            log2[idx] = log2[idx // 2] + 1
            
        max_log = log2[num_segs] + 1
        st = [[0] * max_log for _ in range(num_segs)]
        for idx in range(num_segs):
            st[idx][0] = ans[idx]
        
        for j in range(1, max_log):
            for idx in range(num_segs - (1 << j) + 1):
                st[idx][j] = max(st[idx][j-1], st[idx + (1 << (j-1))][j-1])
                
        def query_rmq(L, R):
            if L > R: return 0
            j = log2[R - L + 1]
            return max(st[L][j], st[R - (1 << j) + 1][j])

        def get_seg(idx):
            # Returns the segment index containing the string index 'idx'
            return bisect.bisect_right(seg_start, idx) - 1
            
        # 4. Process queries
        res = []
        for L, R in queries:
            s_L = get_seg(L)
            s_R = get_seg(R)
            
            # Find the first 0-segment in the query range
            seg_first0 = s_L
            if seg_val[seg_first0] == 1:
                seg_first0 += 1
                
            if seg_first0 > s_R or (seg_first0 == s_R and seg_val[s_R] == 1):
                res.append(tot_ones)
                continue
                
            # Find the last 0-segment in the query range
            seg_last0 = s_R
            if seg_val[seg_last0] == 1:
                seg_last0 -= 1
                
            if seg_first0 >= seg_last0:
                res.append(tot_ones)
                continue
                
            # Calculate maximum possible gain inside the query window
            if seg_first0 + 1 == seg_last0 - 1:
                # Exactly one valid 1-segment between two 0-segments
                left_len = seg_end[seg_first0] - max(L, seg_start[seg_first0]) + 1
                right_len = min(R, seg_end[seg_last0]) - seg_start[seg_last0] + 1
                gain = left_len + right_len
            else:
                # Multiple valid 1-segments exist
                # Case 1: First valid 1-segment (left 0 is cut by L, right 0 is fully inside)
                left_len_1 = seg_end[seg_first0] - max(L, seg_start[seg_first0]) + 1
                right_len_1 = seg_end[seg_first0 + 2] - seg_start[seg_first0 + 2] + 1
                gain1 = left_len_1 + right_len_1
                
                # Case 2: Last valid 1-segment (left 0 is fully inside, right 0 is cut by R)
                left_len_2 = seg_end[seg_last0 - 2] - seg_start[seg_last0 - 2] + 1
                right_len_2 = min(R, seg_end[seg_last0]) - seg_start[seg_last0] + 1
                gain2 = left_len_2 + right_len_2
                
                # Case 3: Middle valid 1-segments (both adjacent 0s are fully inside)
                gain3 = query_rmq(seg_first0 + 3, seg_last0 - 3)
                
                gain = max(gain1, gain2, gain3)
                
            res.append(tot_ones + gain)
            
        return res