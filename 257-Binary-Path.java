import java.util.*;
import java.lang.*;
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

    public void func(TreeNode root, String str) {
        if(root!=null) {
            str = str + "->" + Integer.toString(root.val);
            if(root.left==null && root.right==null) {
                list.add(str);
            }
            func(root.left, str);
            func(root.right, str);
        }
    }

    public List<String> binaryTreePaths(TreeNode root) {
        if(root!=null && root.left==null && root.right==null) {
            list.add(Integer.toString(root.val));
        }
        if(root!=null) {
            String str =  Integer.toString(root.val);
            func(root.left, str);
            func(root.right, str);
        }
        return list;
    }
}