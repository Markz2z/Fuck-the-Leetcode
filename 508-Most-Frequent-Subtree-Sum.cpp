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
    int subtree_sum(map<int, int>& map_, TreeNode* root) {
        if (root==NULL) return 0;
        int result = root->val + subtree_sum(map_, root->left) + subtree_sum(map_, root->right);
        map<int, int>::iterator iter;
        if ((iter = map_.find(result)) != map_.end()) {
            iter->second++;
        } else {
            map_.insert(pair<int, int>(result, 1));
        }
        return result;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        if (root==NULL) return result;
        map<int, int> cnt_map;
        subtree_sum(cnt_map, root);
        map<int, int>::iterator iter;
        int max = 0;
        for (iter = cnt_map.begin(); iter != cnt_map.end(); ++iter) {
            if (iter->second > max) {
                result.clear();
                result.push_back(iter->first);
                max = iter->second;
            } else if (iter->second==max) {
                result.push_back(iter->first);
            }
        }
        return result;
    }
};