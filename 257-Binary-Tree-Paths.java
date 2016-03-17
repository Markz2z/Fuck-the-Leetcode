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
	List<String> list = new ArrayList<String>();

    public List<String> binaryTreePaths(TreeNode root) {
        if(root!=null) {
        	binaryTreePathSearch(TreeNode, root.val);	
        }
        return list;
    }
}