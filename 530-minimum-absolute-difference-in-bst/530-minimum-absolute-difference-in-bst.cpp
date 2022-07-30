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
    int abs(int a, int b){
        return (a > b)?(a - b):(b - a);
    }
    int searchLeft(TreeNode* root){
        if(root == NULL) return INT_MAX;
        if(root->left == NULL){
            return root->val;
        }
        return searchLeft(root->left);
    }
    int searchRight(TreeNode* root){
        if(root == NULL) return INT_MAX;
        if(root->right == NULL){
            return root->val;
        }
        return searchRight(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL) return INT_MAX;
        if(root->left != NULL && root->right != NULL){
            int temp = min(abs(root->val, searchLeft(root->right)), abs(root->val, searchRight(root->left)));
            return min(temp, min(getMinimumDifference(root->left), getMinimumDifference(root->right)));
        }
        if(root->left != NULL){
            return min(abs(root->val, searchRight(root->left)), getMinimumDifference(root->left));
        } 
        if(root->right != NULL){
            return min(abs(root->val, searchLeft(root->right)), getMinimumDifference(root->right));
        }
        return INT_MAX;
    }
};