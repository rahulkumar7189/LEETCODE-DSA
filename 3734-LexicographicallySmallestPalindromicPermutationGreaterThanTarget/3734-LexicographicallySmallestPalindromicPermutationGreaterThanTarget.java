// Last updated: 9/11/2026, 11:32:07 PM
class Solution {
    public String lexPalindromicPermutation(String s, String target) {
        int n = s.length();
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            cnt[c - 'a']++;
        }

        // Check if a palindrome permutation is possible at all
        int oddCount = 0;
        for (int count : cnt) {
            if (count % 2 != 0) oddCount++;
        }
        if (oddCount > 1) return "";

        int L = (n + 1) / 2;

        // Iterate on the length of the prefix matching with target from L down to 0
        for (int i = L; i >= 0; i--) {
            int[] remCnt = cnt.clone();
            boolean canFormPrefix = true;
            char[] firstHalf = new char[L];

            // Try to form the prefix of target of length i
            for (int j = 0; j < i; j++) {
                char ch = target.charAt(j);
                int idx = ch - 'a';
                if (j < n / 2) {
                    if (remCnt[idx] >= 2) {
                        remCnt[idx] -= 2;
                        firstHalf[j] = ch;
                    } else {
                        canFormPrefix = false;
                        break;
                    }
                } else { // Middle character for odd length
                    if (remCnt[idx] >= 1) {
                        remCnt[idx] -= 1;
                        firstHalf[j] = ch;
                    } else {
                        canFormPrefix = false;
                        break;
                    }
                }
            }

            if (!canFormPrefix) continue;

            if (i == L) {
                // If it perfectly matches target's first half, build and check if it beats target
                String candidate = buildPalindrome(firstHalf, n);
                if (candidate.compareTo(target) > 0) {
                    return candidate;
                }
            } else {
                // Try to branch at index i with a character strictly greater than target.charAt(i)
                char targetChar = target.charAt(i);
                boolean foundBranch = false;

                for (int c = targetChar - 'a' + 1; c < 26; c++) {
                    if (i < n / 2) {
                        if (remCnt[c] >= 2) {
                            remCnt[c] -= 2;
                            firstHalf[i] = (char) ('a' + c);
                            if (isValidPalindromeConfig(remCnt, n - 2 * (i + 1))) {
                                foundBranch = true;
                                break;
                            }
                            remCnt[c] += 2; // Backtrack
                        }
                    } else { // Middle character
                        if (remCnt[c] >= 1) {
                            remCnt[c] -= 1;
                            firstHalf[i] = (char) ('a' + c);
                            if (isValidPalindromeConfig(remCnt, n - 2 * i - 1)) {
                                foundBranch = true;
                                break;
                            }
                            remCnt[c] += 1; // Backtrack
                        }
                    }
                }

                if (foundBranch) {
                    // Greedily fill the rest of the first half with the smallest available characters
                    for (int k = i + 1; k < L; k++) {
                        if (k < n / 2) {
                            for (int c = 0; c < 26; c++) {
                                if (remCnt[c] >= 2) {
                                    remCnt[c] -= 2;
                                    firstHalf[k] = (char) ('a' + c);
                                    break;
                                }
                            }
                        } else { // Middle character
                            for (int c = 0; c < 26; c++) {
                                if (remCnt[c] >= 1) {
                                    remCnt[c] -= 1;
                                    firstHalf[k] = (char) ('a' + c);
                                    break;
                                }
                            }
                        }
                    }
                    return buildPalindrome(firstHalf, n);
                }
            }
        }

        return "";
    }

    private boolean isValidPalindromeConfig(int[] remCnt, int remLen) {
        int odd = 0;
        for (int count : remCnt) {
            if (count % 2 != 0) odd++;
        }
        return odd <= (remLen % 2);
    }

    private String buildPalindrome(char[] firstHalf, int n) {
        StringBuilder sb = new StringBuilder();
        int halfLen = n / 2;
        for (int i = 0; i < halfLen; i++) {
            sb.append(firstHalf[i]);
        }
        String firstPart = sb.toString();
        String midPart = (n % 2 != 0) ? String.valueOf(firstHalf[halfLen]) : "";
        String secondPart = new StringBuilder(firstPart).reverse().toString();
        return firstPart + midPart + secondPart;
    }
}
