#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode;
TreeNode* replacePointer(TreeNode* root);

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> vec_temp;
    stack<TreeNode*> record_node;
    while(root!=NULL){
        if(root->left!=NULL){
            record_node.push(replacePointer(root));
            root = root->left;
        }
        else if(root->right!=NULL){
            cout<<root->val<<" ";
            vec_temp.push_back(root->val);
            root = root->right;
        }else{
            cout<<root->val<<" ";
            vec_temp.push_back(root->val);
            if(record_node.size()!=0){
                root = record_node.top();
                record_node.pop();
                cout<<root->val<<" ";
                vec_temp.push_back(root->val);
                root = root->right;
                while(root==NULL && record_node.size()>0){
                    root = record_node.top();
                    record_node.pop();
                    cout<<root->val<<" ";
                    vec_temp.push_back(root->val);
                    root = root->right;
                }
            }else{
                return vec_temp;
            }
        }
    }
    return vec_temp;
}

TreeNode* replacePointer(TreeNode* root){
    TreeNode* ptr = root;
    return ptr;
}

int main(){
    TreeNode* root = (TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 2;
    root->left = NULL;
    root->right = NULL;
    
    TreeNode* root_left;
    root_left = (TreeNode *)malloc(sizeof(struct TreeNode));
    root_left->val = 3;
    root->left = root_left;
    root_left->left = NULL;
    root_left->right = NULL;
    
    TreeNode* root_right;
    root_right = (TreeNode *)malloc(sizeof(struct TreeNode));
    root_right->val = 2;
    //root->right = root_right;
    root_right->left = NULL;
    root_right->right = NULL;

    TreeNode* root_right_left;
    root_right_left = (TreeNode *)malloc(sizeof(struct TreeNode));
    root_right_left->val = 3;
    root_right->left = root_right_left;
    root_right_left->left = NULL;
    root_right_left->right = NULL;
    
    TreeNode* root_left_left;
    root_left_left = (TreeNode *)malloc(sizeof(struct TreeNode));
    root_left_left->val = 1;
    root_left_left->left = NULL;
    root_left_left->right = NULL;
    root_left->left = root_left_left;
    
    TreeNode* root_left_right;
    root_left_right = (TreeNode *)malloc(sizeof(struct TreeNode));
    root_left_right->val = 3;
    //root_left->right = root_left_right;

    TreeNode* root_left_right_left;
    root_left_right_left = (TreeNode *)malloc(sizeof(struct TreeNode));
    root_left_right_left->val = 1;
    root_left_right_left->left = NULL;
    root_left_right_left->right = NULL;
    root_left_right->left = root_left_right_left;

    TreeNode* root_left_right_right;
    root_left_right_right = (TreeNode *)malloc(sizeof(struct TreeNode));
    root_left_right_right->val = 2;
    root_left_right_right->left = NULL;
    root_left_right_right->right = NULL;
    root_left_right->right = root_left_right_right;
    
    inorderTraversal(root);
    //cout<<root->left->val<<std::endl;
}

