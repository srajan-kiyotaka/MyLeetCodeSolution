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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* temp = root;
        while(temp != NULL || !st.empty()){
            while(temp != NULL){
                st.push(temp);
                temp = temp->left;
            }
            k--;
            temp = st.top();
            st.pop();
            if(k == 0){
                return temp->val;
            }
            temp = temp->right;
        }
        return 0;
    }
};