// Last updated: 7/5/2026, 11:02:59 PM
class Solution {
    
    // Fenwick Tree (Binary Indexed Tree) to maintain the maximum gaps
    class FenwickTree {
        int[] tree;
        
        public FenwickTree(int n) {
            tree = new int[n];
        }
        
        // Point update: updates the maximum gap ending at index i
        public void update(int i, int val) {
            while (i < tree.length) {
                tree[i] = Math.max(tree[i], val);
                i += i & -i; // Move to the next responsible node
            }
        }
        
        // Prefix query: gets the maximum gap ending at or before index i
        public int query(int i) {
            int res = 0;
            while (i > 0) {
                res = Math.max(res, tree[i]);
                i -= i & -i; // Move to the parent node
            }
            return res;
        }
    }

    public List<Boolean> getResults(int[][] queries) {
        // Find the maximum x coordinate to size our Fenwick Tree safely
        int maxX = 0;
        for (int[] q : queries) {
            maxX = Math.max(maxX, q[1]);
        }
        
        // +5 provides a safe buffer for our right sentinel
        FenwickTree tree = new FenwickTree(maxX + 5);
        TreeSet<Integer> obstacles = new TreeSet<>();
        
        // Sentinels to prevent NullPointerExceptions
        obstacles.add(0);
        obstacles.add(maxX + 2); 
        
        // 1. Simulate all type 1 queries to get the final obstacle layout
        for (int[] q : queries) {
            if (q[0] == 1) {
                obstacles.add(q[1]);
            }
        }
        
        // 2. Initialize the Fenwick tree with the final gaps
        int prev = 0;
        for (int x : obstacles) {
            if (x > 0) {
                tree.update(x, x - prev);
                prev = x;
            }
        }
        
        List<Boolean> ans = new ArrayList<>();
        
        // 3. Process queries in reverse!
        for (int i = queries.length - 1; i >= 0; i--) {
            int[] q = queries[i];
            
            if (q[0] == 1) {
                // Type 1: Backward "addition" is actually an obstacle removal.
                // Removing an obstacle merges the two adjacent gaps into a bigger one.
                int x = q[1];
                obstacles.remove(x);
                
                int lower = obstacles.lower(x);
                int higher = obstacles.higher(x);
                tree.update(higher, higher - lower);
                
            } else {
                // Type 2: Check if block of size `sz` can fit in [0, x]
                int x = q[1];
                int sz = q[2];
                
                // Find the last obstacle that comes before or exactly at x
                int prevObs = obstacles.floor(x);
                
                // Max gap strictly contained completely between obstacles <= x
                int maxGap = tree.query(prevObs);
                
                // The gap between the last obstacle <= x and x itself
                int lastGap = x - prevObs;
                
                // If either space is large enough, it's possible!
                ans.add(maxGap >= sz || lastGap >= sz);
            }
        }
        
        // 4. Reverse the answers back to the original chronological order
        Collections.reverse(ans);
        return ans;
    }
}