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
    vector<int> ans;
    void inorder(TreeNode* root){
        if(root == NULL) return ;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
        // delete root;
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        root = NULL;
        TreeNode* pre = NULL;
        for(int i = 0; i < ans.size(); i++){
            if(i == 0){
                root = new TreeNode;
                root->val = ans[i];
                pre = root;
            }
            else{
                TreeNode* temp = new TreeNode;
                temp->val = ans[i];
                pre->right = temp;
                pre = temp;
            }
        }
        return root;
    }
};