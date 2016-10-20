/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* getMid(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* slow_prev = nullptr;
		while(fast) {
			if (fast) {
				fast = fast->next;
			}
			if (fast) {
				fast = fast->next;
				slow_prev = slow;
				slow = slow->next;
			}
		}
		if (slow_prev) slow_prev->next = nullptr;
		return slow;
	}

    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* mid = nullptr;
        TreeNode* tree_mid = nullptr;
        if (head) {
            mid = getMid(head);
            if (mid) {
                tree_mid = new TreeNode(mid->val);
                TreeNode* left_root = nullptr;
                TreeNode* right_root = nullptr;
                if (mid!=head) left_root = sortedListToBST(head);
                if (mid) right_root = sortedListToBST(mid->next);
                tree_mid->left = left_root;
                tree_mid->right = right_root;
            }
        }
        return tree_mid;
    }
};