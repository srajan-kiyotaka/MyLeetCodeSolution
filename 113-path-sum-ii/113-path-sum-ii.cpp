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
    vector<vector<int>> result;
    
    void path(TreeNode* root, int targetSum, vector<int> temp){
        if(root == NULL) return;
        temp.push_back(root->val);
        if(root->val == targetSum && root->left == NULL && root->right == NULL){
            result.push_back(temp);
            return;
        }
        if(root->left != NULL)
            path(root->left, targetSum - root->val, temp);
        if(root->right != NULL)    
            path(root->right, targetSum - root->val, temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        path(root, targetSum, temp);
        return result;
    }
};