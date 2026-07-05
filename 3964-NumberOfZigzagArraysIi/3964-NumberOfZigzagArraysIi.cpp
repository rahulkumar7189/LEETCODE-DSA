// Last updated: 7/5/2026, 11:02:44 PM
#include <vector>

using namespace std;

class Solution {
private:
    long long MOD = 1e9 + 7;

    // Helper function to multiply two square matrices
    vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B, int size) {
        vector<vector<long long>> C(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int k = 0; k < size; ++k) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < size; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    // Helper function for fast matrix exponentiation
    vector<vector<long long>> power(vector<vector<long long>> A, long long p, int size) {
        vector<vector<long long>> res(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i) res[i][i] = 1; // Identity matrix

        while (p > 0) {
            if (p & 1) res = multiply(res, A, size);
            A = multiply(A, A, size);
            p >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        if (n == 1) return m;

        int size = 2 * m;
        // T matrix of size 2m x 2m
        // States 0 to m-1: UP states (expecting next element to be larger)
        // States m to 2m-1: DOWN states (expecting next element to be smaller)
        vector<vector<long long>> T(size, vector<long long>(size, 0));

        for (int x = 0; x < m; ++x) {
            // From UP[x] (state x), we can go to DOWN[y] (state m + y) for all y > x
            for (int y = x + 1; y < m; ++y) {
                T[m + y][x] = 1;
            }
            // From DOWN[x] (state m + x), we can go to UP[y] (state y) for all y < x
            for (int y = 0; y < x; ++y) {
                T[y][m + x] = 1;
            }
        }

        // Exponentiate the transition matrix to power (n - 1)
        vector<vector<long long>> Tn = power(T, n - 1, size);

        // Initial base cases for length 1: 
        // Any value x can be the start of either an UP sequence or a DOWN sequence.
        long long total_valid_arrays = 0;

        // Sum up transitions from all valid starting configurations
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                total_valid_arrays = (total_valid_arrays + Tn[i][j]) % MOD;
            }
        }

        return total_valid_arrays;
    }
};