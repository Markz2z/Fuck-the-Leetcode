/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    private TreeNode wrongNode1 = null;
    private TreeNode wrongNode2 = null;
    private TreeNode prevNode = null;
    
    public void inorderTraverse(TreeNode root) {
        if (root != null) {
            inorderTraverse(root.left);
            if (prevNode != null && prevNode.val > root.val) {
                wrongNode1 = wrongNode1 == null ? prevNode : wrongNode1;
                wrongNode2 = root;
            }
            prevNode = root;
            inorderTraverse(root.right);
        }
    }
    
    public void recoverTree(TreeNode root) {
        inorderTraverse(root);
        if (wrongNode1!=null) {
            int tmp = wrongNode1.val;
            wrongNode1.val = wrongNode2.val;
            wrongNode2.val = tmp;
        }
    }
}