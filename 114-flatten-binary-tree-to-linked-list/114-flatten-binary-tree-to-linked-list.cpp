/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    queue<TreeNode*> q;
    
    void preorder(TreeNode* root){
        if(root == NULL) return;
        q.push(root);        
        preorder(root->left);
        preorder(root->right);
    }
    
    void flatten(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) return;
        preorder(root);
        int len = q.size();
        // cout << len << endl;
        for(int i = 0; i < len; i++){
            TreeNode* temp = q.front();
            q.pop();
            temp->left = NULL;
            if(i == len - 1){
                temp->right = NULL;
            }
            else{
                temp->right = q.front();
            }
            
        }
    }
};