// Last updated: 7/5/2026, 11:03:19 PM
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public TreeNode createBinaryTree(int[][] descriptions) {
        // Map to keep track of created nodes by their values
        Map<Integer, TreeNode> nodeMap = new HashMap<>();
        // Set to keep track of all values that are children
        Set<Integer> children = new HashSet<>();
        
        for (int[] desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            boolean isLeft = desc[2] == 1;
            
            // Get or create parent node
            TreeNode parentNode = nodeMap.computeIfAbsent(parentVal, TreeNode::new);
            // Get or create child node
            TreeNode childNode = nodeMap.computeIfAbsent(childVal, TreeNode::new);
            
            // Link the parent to the child based on isLeft flag
            if (isLeft) {
                parentNode.left = childNode;
            } else {
                parentNode.right = childNode;
            }
            
            // Mark this node value as a child
            children.add(childVal);
        }
        
        // The root node is the one that never appeared as a child
        for (int val : nodeMap.keySet()) {
            if (!children.contains(val)) {
                return nodeMap.get(val);
            }
        }
        
        return null;
    }
}