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
    private static int INT_MIN = -10000;
    private static int gMax = INT_MIN;
    public int getMax(int num1, int num2) {
        return num1 > num2 ? num1 : num2;
    }

    public int maxPath(TreeNode root) {
        int cur = INT_MIN;
        int max = INT_MIN;
        if (root != null) {
            cur = root.val;
            int left = maxPath(root.left);
            int right = maxPath(root.right);
            if (left > 0 || right > 0) cur = left > right ? cur + left : cur + right;
            if (left > 0 && right > 0) {
                max = root.val + left + right;
            } else {
                max = cur;
            }
            gMax = gMax > max ? gMax : max;
        }
        return cur;
    }

    public int maxPathSum(TreeNode root) {
        gMax = INT_MIN;
        maxPath(root);
        return gMax;
    }
}