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
    int search(vector<int>& inorder, int target){
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == target) return i;
        }
        return -1;
    }

    TreeNode* createTree(vector<int>& inorder, vector<int>& postorder, int s, int e){
        if(s < 0 || s > e) return NULL;
        if(s == e){
            TreeNode* node = new TreeNode(inorder[s]);
            postorder.pop_back();
            return node;
        }
        int it = postorder.back();
        int m = search(inorder, it);
        TreeNode* node = new TreeNode(it);
        postorder.pop_back();
        node->right = createTree(inorder, postorder, m+1, e);
        node->left = createTree(inorder, postorder, s, m-1);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() < 1) return NULL;
        return createTree(inorder, postorder, 0, inorder.size() - 1);
    }
};