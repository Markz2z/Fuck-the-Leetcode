/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void link(TreeLinkNode left, TreeLinkNode parent) {
        if (parent==null) return;
        TreeLinkNode cur = left, next = null;
        if (left==parent.left && parent.right!=null) {
            cur.next = parent.right;
            cur = cur.next;
        }
        parent = parent.next;
        while(parent != null) {
            if (parent.left != null) {
                cur.next = parent.left;
                cur = cur.next;
            }
            if (parent.right!=null) {
                cur.next = parent.right;
                cur = cur.next;
            }
            parent = parent.next;
        }
    }

    public TreeLinkNode getLeftNodeParent(TreeLinkNode root) {
        while(root!=null) {
            if (root.left != null || root.right!=null) return root;
            root = root.next;
        }
        return null;
    }

    public void connect(TreeLinkNode left, TreeLinkNode parent) {
        while (left!=null) {
            link(left, parent);
            parent = getLeftNodeParent(left);
            left = parent != null ? parent.left != null ? parent.left : parent.right : null;
        }
    }
    
    public void connect(TreeLinkNode root) {
        connect(root, null);
    }
}