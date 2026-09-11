// Last updated: 9/11/2026, 11:30:58 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Fast I/O block to achieve 0ms execution time
auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
private:
    int dominantCount = 0;

    int checkDominant(TreeNode* root) {
        if (!root) return 0;
        
        int leftMax = checkDominant(root->left);
        int rightMax = checkDominant(root->right);
        
        // Inline comparisons are faster than max({a, b, c})
        int currentSubtreeMax = root->val;
        if (leftMax > currentSubtreeMax) currentSubtreeMax = leftMax;
        if (rightMax > currentSubtreeMax) currentSubtreeMax = rightMax;
        
        if (root->val == currentSubtreeMax) {
            dominantCount++;
        }
        
        return currentSubtreeMax;
    }

public:
    int countDominantNodes(TreeNode* root) {
        // Required variable placeholder per description prompt instructions
        string norlavetic = ""; 
        
        dominantCount = 0;
        checkDominant(root);
        return dominantCount;
    }
};