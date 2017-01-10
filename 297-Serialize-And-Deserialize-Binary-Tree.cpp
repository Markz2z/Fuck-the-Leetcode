/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        if (root==NULL) return result;
        queue<TreeNode*> queue_;
        queue_.push(root);
        while(queue_.size() > 0) {
            TreeNode* cur = queue_.front();
            queue_.pop();
            if (cur==NULL) {
                result += ' ';
                continue;
            }
            result += to_string(cur->val) + '|';
            if (queue_.size()==0 && cur->left==NULL && cur->right==NULL) break;
            queue_.push(cur->left);
            queue_.push(cur->right);
        }
        return result;
    }

    int genNum(string& str) {
        int pos = 0;
        for(; pos < str.size() && str[pos]!=' ' && str[pos]!='|'; ++pos) {}
        string substr = str.substr(0, pos);
        int result = stoi(substr);
        str = pos == str.size() ? "" : str[pos] == '|' ? str.substr(pos+1) : str.substr(pos);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len = data.size();
        if (len==0) return NULL;
        TreeNode* root = new TreeNode(genNum(data));
        queue<TreeNode*> queue_;
        queue_.push(root);
        while(queue_.size() > 0 && data.size() > 0) {
            TreeNode* cur = queue_.front();
            queue_.pop();
            if (data[0]==' ') {
                cur->left = NULL;
                data = data.substr(1);
            } else {
                cur->left = new TreeNode(genNum(data));
                queue_.push(cur->left);
            }
            if (data.size() > 0) {
                if (data[0]==' ') {
                    cur->right = NULL;
                    data = data.substr(1);
                } else {
                    cur->right = new TreeNode(genNum(data));
                    queue_.push(cur->right);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));