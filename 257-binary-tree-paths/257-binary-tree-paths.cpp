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
    vector<vector<int>> store;
    
    void path(TreeNode* root){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->val);
            store.push_back(ans);
            ans.pop_back();
            return;
        }
        ans.push_back(root->val);
        if(root->left != NULL)
            path(root->left);
        if(root->right != NULL)
            path(root->right);
        ans.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        path(root);
        vector<string> result;
        for(int i = 0; i < store.size(); i++){
            string temp = to_string(store[i][0]);
            for(int j = 1; j < store[i].size(); j++){
                temp = temp + "->" + to_string(store[i][j]);
            }
            result.push_back(temp);
        }
        return result;
    }
};