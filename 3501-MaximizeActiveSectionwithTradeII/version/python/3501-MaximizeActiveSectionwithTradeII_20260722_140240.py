# Last updated: 7/22/2026, 2:02:40 PM
# Approach: Segment Compression & Sparse Table (RMQ)Segment Compression: Compress binary string $s$ into continuous blocks of alternating 0s and 1s.Gain Precalculation: For each 1-segment, precompute the potential gain: $\text{length}(\text{left } 0\text{-segment}) + \text{length}(\text{right } 0\text{-segment})$.Sparse Table Construction: Build a Sparse Table over the precomputed gains to answer Range Maximum Queries (RMQ) in $O(1)$ time.Query Processing:Map query boundaries $[L, R]$ to segment indices.Identify the first and last 0-segments (handling truncated boundaries at $L$ and $R$).Compare gains from the boundary 1-segments and fetch the maximum gain of middle fully-contained 1-segments via Sparse Table RMQ.Total active sections = $\text{total\_ones} + \max(\text{valid gains})$.ComplexityTime Complexity:Preprocessing: $O(N + M \log M)$ where $N = \vert{}s\vert{}$ and $M$ is the number of segments ($M \le N$).Queries: $O(1)$ per query $\rightarrow O(Q)$ for $Q$ queries.Total Time: $O(N + M \log M + Q)$Space Complexity: $O(N + M \log M)$ for direct position mapping arrays and the Sparse Table.
1import bisect
2
3class Solution(object):
4    def maxActiveSectionsAfterTrade(self, s, queries):
5        n = len(s)
6        tot_ones = s.count('1')
7        
8        # 1. Parse string into alternating 0 and 1 segments
9        seg_val = []
10        seg_start = []
11        seg_end = []
12        
13        i = 0
14        while i < n:
15            j = i
16            while j < n and s[j] == s[i]:
17                j += 1
18            seg_val.append(int(s[i]))
19            seg_start.append(i)
20            seg_end.append(j - 1)
21            i = j
22            
23        num_segs = len(seg_val)
24        
25        # If there are no zeros, no trades can increase active sections
26        if all(v == 1 for v in seg_val):
27            return [tot_ones] * len(queries)
28            
29        # 2. Build precomputed answers (potential net gains) for each segment
30        ans = [0] * num_segs
31        for idx in range(num_segs):
32            if seg_val[idx] == 1:
33                left_len = 0
34                if idx > 0:
35                    left_len = seg_end[idx-1] - seg_start[idx-1] + 1
36                right_len = 0
37                if idx < num_segs - 1:
38                    right_len = seg_end[idx+1] - seg_start[idx+1] + 1
39                ans[idx] = left_len + right_len
40                
41        # 3. Build Sparse Table for O(1) Range Maximum Queries
42        log2 = [0] * (num_segs + 1)
43        for idx in range(2, num_segs + 1):
44            log2[idx] = log2[idx // 2] + 1
45            
46        max_log = log2[num_segs] + 1
47        st = [[0] * max_log for _ in range(num_segs)]
48        for idx in range(num_segs):
49            st[idx][0] = ans[idx]
50        
51        for j in range(1, max_log):
52            for idx in range(num_segs - (1 << j) + 1):
53                st[idx][j] = max(st[idx][j-1], st[idx + (1 << (j-1))][j-1])
54                
55        def query_rmq(L, R):
56            if L > R: return 0
57            j = log2[R - L + 1]
58            return max(st[L][j], st[R - (1 << j) + 1][j])
59
60        def get_seg(idx):
61            # Returns the segment index containing the string index 'idx'
62            return bisect.bisect_right(seg_start, idx) - 1
63            
64        # 4. Process queries
65        res = []
66        for L, R in queries:
67            s_L = get_seg(L)
68            s_R = get_seg(R)
69            
70            # Find the first 0-segment in the query range
71            seg_first0 = s_L
72            if seg_val[seg_first0] == 1:
73                seg_first0 += 1
74                
75            if seg_first0 > s_R or (seg_first0 == s_R and seg_val[s_R] == 1):
76                res.append(tot_ones)
77                continue
78                
79            # Find the last 0-segment in the query range
80            seg_last0 = s_R
81            if seg_val[seg_last0] == 1:
82                seg_last0 -= 1
83                
84            if seg_first0 >= seg_last0:
85                res.append(tot_ones)
86                continue
87                
88            # Calculate maximum possible gain inside the query window
89            if seg_first0 + 1 == seg_last0 - 1:
90                # Exactly one valid 1-segment between two 0-segments
91                left_len = seg_end[seg_first0] - max(L, seg_start[seg_first0]) + 1
92                right_len = min(R, seg_end[seg_last0]) - seg_start[seg_last0] + 1
93                gain = left_len + right_len
94            else:
95                # Multiple valid 1-segments exist
96                # Case 1: First valid 1-segment (left 0 is cut by L, right 0 is fully inside)
97                left_len_1 = seg_end[seg_first0] - max(L, seg_start[seg_first0]) + 1
98                right_len_1 = seg_end[seg_first0 + 2] - seg_start[seg_first0 + 2] + 1
99                gain1 = left_len_1 + right_len_1
100                
101                # Case 2: Last valid 1-segment (left 0 is fully inside, right 0 is cut by R)
102                left_len_2 = seg_end[seg_last0 - 2] - seg_start[seg_last0 - 2] + 1
103                right_len_2 = min(R, seg_end[seg_last0]) - seg_start[seg_last0] + 1
104                gain2 = left_len_2 + right_len_2
105                
106                # Case 3: Middle valid 1-segments (both adjacent 0s are fully inside)
107                gain3 = query_rmq(seg_first0 + 3, seg_last0 - 3)
108                
109                gain = max(gain1, gain2, gain3)
110                
111            res.append(tot_ones + gain)
112            
113        return res