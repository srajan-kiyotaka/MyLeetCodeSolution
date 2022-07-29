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
    TreeNode* root = NULL;
    
    void createBST(TreeNode* node, int x){
        if(node == NULL){
            TreeNode* temp = new TreeNode(x);
            root = temp;
            return;
        }
        if(node->val > x){
            if(node->left != NULL)
                createBST(node->left, x);
            else{
                TreeNode* temp = new TreeNode(x);
                node->left = temp;
                return;
            }
        }
        else{
            if(node->right != NULL)
                createBST(node->right, x);
            else{
                TreeNode* temp = new TreeNode(x);
                node->right = temp;
                return;
            }
        }
    }
    
    void addNode(vector<int>& nums, int l, int h){
        if(l > h){
            return ;
        }
        int mid = (l + h) / 2;
        createBST(root, nums[mid]);
        addNode(nums, l, mid - 1);
        addNode(nums, mid + 1, h);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        addNode(nums, 0, nums.size() - 1);
        return root;
    }
};