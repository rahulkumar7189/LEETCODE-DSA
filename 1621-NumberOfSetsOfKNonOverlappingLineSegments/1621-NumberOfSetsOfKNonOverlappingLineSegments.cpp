// Last updated: 9/23/2026, 8:03:07 PM
class Solution {
    int MOD = 1e9 + 7;
    
    // Function to calculate (base^exp) % MOD
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    
    // Function to find modular inverse of n modulo MOD
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    int numberOfSets(int n, int k) {
        int N = n + k - 1;
        int K = 2 * k;
        
        // If we don't have enough points to pick 2*k points, return 0
        if (N < K) return 0;
        
        long long res = 1;
        
        // Calculate N! / (K! * (N-K)!) % MOD
        // We do this by calculating (N * (N-1) * ... * (N-K+1)) / (1 * 2 * ... * K)
        for (int i = 1; i <= K; i++) {
            res = (res * (N - i + 1)) % MOD;
            res = (res * modInverse(i)) % MOD;
        }
        
        return res;
    }
};