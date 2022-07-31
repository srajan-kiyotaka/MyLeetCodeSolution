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
    vector<int> result;
    
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return result;
        deque<TreeNode*> dq;
        
        dq.push_back(root);
        while(!dq.empty()){
            TreeNode* rightmost = NULL;
            int len = dq.size();
            for(int i = 0; i < len; i++){
                rightmost = dq.front();
                dq.pop_front();
                if(rightmost->left != NULL) dq.push_back(rightmost->left);
                if(rightmost->right != NULL) dq.push_back(rightmost->right);
            }
            if(rightmost != NULL){
                result.push_back(rightmost->val);
            }
        }
        return result;
    }
};