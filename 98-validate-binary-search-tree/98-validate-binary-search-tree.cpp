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
    bool bst(TreeNode* root, long long l, long long h){
        if(root == NULL) return true;
        if(root->val < h && root->val > l){
            return bst(root->left, l, root->val) && bst(root->right, root->val, h);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        return bst(root, LONG_MIN, LONG_MAX);
    }
};