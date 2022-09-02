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
    vector<double> bfs(TreeNode* root){
        queue<TreeNode*> q;
        vector<double> ans;
        
        q.push(root);
        
        while(!q.empty()){
            double sum = 0;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* current_node = q.front();
                q.pop();
                sum += current_node->val;
                
                if(current_node->left != NULL)
                    q.push(current_node->left);
                if(current_node->right != NULL)
                    q.push(current_node->right);
            }
            ans.push_back((double)(sum/size));
        }
        
        return ans;
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result = bfs(root);
        return result;
    }
};