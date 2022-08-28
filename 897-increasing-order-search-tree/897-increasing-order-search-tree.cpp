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
    vector<TreeNode*> ans;
    void inorder(TreeNode* root){
        if(root == NULL) return ;
        inorder(root->left);
        ans.push_back(root);
        inorder(root->right);
        // delete root;
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        TreeNode* pre = NULL;
        for(int i = 0; i < ans.size(); i++){
            if(i == 0){
                root = ans[i];
                root->left = NULL;
                pre = root;
            }
            else{
                TreeNode* temp = ans[i];
                temp->left = NULL;
                pre->right = temp;
                pre = temp;
            }
        }
        return root;
    }
};