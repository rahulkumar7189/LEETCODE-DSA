// Last updated: 9/15/2026, 11:54:20 PM
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
class Solution {
    int matchCount = 0;
    
    // Returns a pair of {sum_of_subtree, count_of_nodes}
    std::pair<int, int> dfs(TreeNode* node) {
        if (!node) {
            return {0, 0};
        }
        
        // Post-order traversal: Left, Right, then Root
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        
        int currentSum = left.first + right.first + node->val;
        int currentCount = left.second + right.second + 1;
        
        // Check if the current node's value equals the floor of the average
        if (node->val == currentSum / currentCount) {
            matchCount++;
        }
        
        return {currentSum, currentCount};
    }
    
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return matchCount;
    }
};