// Last updated: 7/5/2026, 11:03:04 PM
class TrieNode {
    TrieNode[] children;
    int bestIndex;

    public TrieNode(int index) {
        children = new TrieNode[26];
        bestIndex = index;
    }
}

class Solution {
    public int[] stringIndices(String[] wordsContainer, String[] wordsQuery) {
        // 1. Find the absolute "best" word for completely empty suffix matches
        int defaultBestIndex = 0;
        for (int i = 1; i < wordsContainer.length; i++) {
            if (wordsContainer[i].length() < wordsContainer[defaultBestIndex].length()) {
                defaultBestIndex = i;
            }
        }
        
        // Initialize root with the default best index
        TrieNode root = new TrieNode(defaultBestIndex);

        // 2. Build the Trie backwards
        for (int i = 0; i < wordsContainer.length; i++) {
            String word = wordsContainer[i];
            TrieNode curr = root;
            
            for (int j = word.length() - 1; j >= 0; j--) {
                int charIdx = word.charAt(j) - 'a';
                
                if (curr.children[charIdx] == null) {
                    curr.children[charIdx] = new TrieNode(i);
                } else {
                    // Evaluate tie-breaker conditions
                    int existingBest = curr.children[charIdx].bestIndex;
                    int existingLen = wordsContainer[existingBest].length();
                    int currLen = word.length();
                    
                    if (currLen < existingLen || (currLen == existingLen && i < existingBest)) {
                        curr.children[charIdx].bestIndex = i;
                    }
                }
                curr = curr.children[charIdx];
            }
        }

        // 3. Process Queries
        int[] ans = new int[wordsQuery.length];
        for (int i = 0; i < wordsQuery.length; i++) {
            String query = wordsQuery[i];
            TrieNode curr = root;
            
            for (int j = query.length() - 1; j >= 0; j--) {
                int charIdx = query.charAt(j) - 'a';
                
                // If the suffix breaks early, the current node holds the best match so far
                if (curr.children[charIdx] == null) {
                    break;
                }
                curr = curr.children[charIdx];
            }
            ans[i] = curr.bestIndex;
        }

        return ans;
    }
}