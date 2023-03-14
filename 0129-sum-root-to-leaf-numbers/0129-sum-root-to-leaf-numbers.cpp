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
    int travelserSum(TreeNode* root, int sum){
        if(root == NULL) return 0; 
        if(root->left == NULL && root->right == NULL){
            return (sum*10 + root->val);
        } 
        sum = sum * 10 + root->val;
        return travelserSum(root->left, sum) + travelserSum(root->right, sum);

    }
    int sumNumbers(TreeNode* root) {
       if(root == NULL) return 0;
       return travelserSum(root, 0);
    }
};