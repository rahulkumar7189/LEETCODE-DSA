// Last updated: 9/15/2026, 11:54:10 PM
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int count = 0;
        
        for (int i = 0; i <= n - k; ) {
            // Check if there is a palindrome of length k
            if (isPalindrome(s, i, i + k - 1)) {
                count++;
                i += k; // Jump past this palindrome
            } 
            // Check if there is a palindrome of length k + 1
            else if (i + k < n && isPalindrome(s, i, i + k)) {
                count++;
                i += k + 1; // Jump past this palindrome
            } 
            // If neither, just move the starting point forward by 1
            else {
                i++;
            }
        }
        
        return count;
    }

private:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};