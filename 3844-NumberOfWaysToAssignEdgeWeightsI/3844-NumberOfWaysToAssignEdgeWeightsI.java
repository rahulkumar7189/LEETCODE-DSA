// Last updated: 7/5/2026, 11:02:51 PM
import java.util.*;

public class Solution {
    private int maxDepth = 0;

    // Fixed the method name and parameters to match what the LeetCode driver expects
    public int assignEdgeWeights(int[][] edges) {
        if (edges == null || edges.length == 0) return 0;

        // Since n is not given, find the maximum node ID to determine the size of the tree
        int n = 0;
        for (int[] edge : edges) {
            n = Math.max(n, Math.max(edge[0], edge[1]));
        }

        // Step 1: Build the adjacency list for the tree
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }

        // Step 2: Find the maximum depth using DFS (Rooted at 1, depth 0)
        maxDepth = 0;
        dfs(1, -1, 0, adj);

        // Step 3: Compute 2^(maxDepth - 1) % (10^9 + 7)
        if (maxDepth == 0) return 0; 
        
        long MOD = 1_000_000_007;
        return (int) power(2, maxDepth - 1, MOD);
    }

    private void dfs(int node, int parent, int currentDepth, List<List<Integer>> adj) {
        maxDepth = Math.max(maxDepth, currentDepth);
        
        for (int neighbor : adj.get(node)) {
            if (neighbor != parent) {
                dfs(neighbor, node, currentDepth + 1, adj);
            }
        }
    }

    // Fast modular exponentiation: (base^exp) % mod
    private long power(long base, long exp, long mod) {
        long res = 1;
        base = base % mod;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
}