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
    bool symmetry(TreeNode* leftside, TreeNode* rightside){
        if(leftside == NULL && rightside == NULL) return true;
        else if(leftside == NULL || rightside == NULL) return false;
        if(leftside->val != rightside->val) return false;
        return (symmetry(leftside->left, rightside->right) && symmetry(leftside->right, rightside->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return symmetry(root->left, root->right);
    }
};