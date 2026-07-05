// Last updated: 7/5/2026, 11:02:47 PM
class Solution {
public:
    char processStr(string s, long long k) {
        // Phase 1: Track the length of the string at each step
        // We use a vector to store lengths after each character operation
        int n = s.length();
        vector<long long> lengths(n, 0);
        long long current_len = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                current_len++;
            } else if (s[i] == '*') {
                if (current_len > 0) {
                    current_len--;
                }
            } else if (s[i] == '#') {
                current_len *= 2;
            } else if (s[i] == '%') {
                // Reversing doesn't change the length
                // current_len stays the same
            }
            lengths[i] = current_len;
        }

        // Out of bounds check
        if (k < 0 || k >= current_len) {
            return '.';
        }

        // Phase 2: Reverse simulation to track index k backwards
        bool is_reversed = false;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '%') {
                // If it's a reverse operation, invert our global reverse tracking state
                // and flip the target index across the current string's midpoint
                is_reversed = !is_reversed;
                long long len = lengths[i];
                k = len - 1 - k;
            } else if (s[i] == '#') {
                // A duplicate operation means the string was doubled.
                // The length before this operation was exactly half.
                long long half_len = lengths[i] / 2;
                if (k >= half_len) {
                    k -= half_len;
                }
            } else if (s[i] == '*') {
                // A backspace character means a character was removed.
                // To step backward through time, we do nothing to k directly, 
                // but the previous state logically included that deleted character.
            } else {
                // It's a lowercase English letter.
                // Check if our tracked index k points to the end of the string at this step.
                long long len = lengths[i];
                if (k == len - 1) {
                    return s[i];
                }
            }
        }

        return '.';
    }
};