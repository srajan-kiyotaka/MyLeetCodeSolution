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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> state;
        if(root == NULL) return true;
        state.push(root);
        bool flag = true;
        long int level = 1;
        while(!state.empty()){
            if(state.size() == level){
                for(int i = 0; i < level; i++){
                    TreeNode* node = state.front();
                    state.pop();
                    if(node->left == NULL && node->right != NULL) return false;
                    else if(node->left != NULL && node->right == NULL){
                        if(flag){
                            flag = false;
                            state.push(node->left);
                        }
                        else return false;
                    }
                    else if(node->left == NULL && node->right == NULL){
                        flag = false;
                    }
                    else{
                        if(!flag) return false;
                        state.push(node->left);
                        state.push(node->right);
                    }
                }
            }
            else{
                while(!state.empty()){
                    TreeNode* node = state.front();
                    state.pop();
                    if(node->left != NULL || node->right != NULL) return false;
                }
            }
            level *= 2;
        }
        return true;
    }
};