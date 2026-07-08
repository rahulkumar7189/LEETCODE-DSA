// Last updated: 7/8/2026, 9:02:23 PM
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;

        // 1. Filter out non-zero digits and track their positions
        vector<int> digits;
        vector<int> orig_to_nz_idx(m, -1);
        
        for (int i = 0; i < m; i++) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
            }
        }

        int n = digits.size();

        // 2. Precompute prefix values and prefix sums for the compressed non-zero list
        vector<long long> P(n + 1, 0);       // Prefix numerical value modulo MOD
        vector<long long> sumPref(n + 1, 0); // Prefix sum of digits
        vector<long long> pow10(n + 1, 1);   // Powers of 10 modulo MOD

        for (int i = 0; i < n; i++) {
            P[i + 1] = (P[i] * 10 + digits[i]) % MOD;
            sumPref[i + 1] = sumPref[i] + digits[i];
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }

        // 3. Map original string indices to compressed non-zero array boundaries
        // next_nz[i] stores the first non-zero index >= i
        vector<int> next_nz(m, n);
        int last = n;
        for (int i = m - 1; i >= 0; i--) {
            if (s[i] != '0') {
                // count how many non-zeros were before this? 
                // A simpler way: map via tracking active pointers
            }
        }

        // Let's rebuild the mapping cleanly:
        // We can just find the actual rank/index of each non-zero element.
        vector<int> nz_rank(m, -1);
        int current_idx = 0;
        for(int i = 0; i < m; i++) {
            if(s[i] != '0') {
                nz_rank[i] = current_idx++;
            }
        }

        // next_nz[i] finds the first non-zero index rank at or after original index i
        vector<int> first_nz_at_or_after(m, n);
        int succ = n;
        for(int i = m - 1; i >= 0; i--) {
            if(s[i] != '0') {
                succ = nz_rank[i];
            }
            first_nz_at_or_after[i] = succ;
        }

        // last_nz[i] finds the last non-zero index rank at or before original index i
        vector<int> last_nz_at_or_before(m, -1);
        int pred = -1;
        for(int i = 0; i < m; i++) {
            if(s[i] != '0') {
                pred = nz_rank[i];
            }
            last_nz_at_or_before[i] = pred;
        }

        // 4. Process Queries
        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];

            // Map original range [l, r] to compressed non-zero range [L, R]
            int L = first_nz_at_or_after[l];
            int R = last_nz_at_or_before[r];

            // If no non-zero digits exist in the range
            if (L > R || L == n || R == -1) {
                answer.push_back(0);
                continue;
            }

            // Calculate x using prefix values: P[R+1] and P[L]
            long long x = (P[R + 1] - (P[L] * pow10[R - L + 1]) % MOD + MOD) % MOD;

            // Calculate the digit sum using prefix sums
            long long digit_sum = sumPref[R + 1] - sumPref[L];

            // Final answer for the query
            long long res = (x * (digit_sum % MOD)) % MOD;
            answer.push_back(res);
        }

        return answer;
    }
};