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
    TreeNode* ans;
    void fun(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(original == NULL) return;
        if(original == target){
            ans = cloned;
            return;
        }
        if(original->left != NULL)
            fun(original->left, cloned->left, target);
        if(original->right != NULL)
            fun(original->right, cloned->right, target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        fun(original, cloned, target);
        return ans;
    }
};