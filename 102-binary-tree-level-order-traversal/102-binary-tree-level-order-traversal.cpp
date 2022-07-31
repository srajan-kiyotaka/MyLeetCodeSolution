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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> result;
        if(root == NULL) return result;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int len = q.size();
            for(int i = 0; i < len; i++){
                TreeNode* node = q.front();
                temp.push_back(node->val);
                q.pop();
                if(node->left != NULL) q.push(node->left);    
                if(node->right != NULL) q.push(node->right);
                   
            }
            if(temp.size() != 0)
                result.push_back(temp);
        }
        return result;
    }
};