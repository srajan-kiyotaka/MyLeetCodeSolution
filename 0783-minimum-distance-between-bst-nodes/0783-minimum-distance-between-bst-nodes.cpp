class Solution {
public:
    // List to store the tree nodes in the inorder traversal.
    vector<int> inorderNodes;
    
    void inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        inorderTraversal(root->left);
        // Store the nodes in the list.
        inorderNodes.push_back(root->val);
        inorderTraversal(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        inorderTraversal(root);
        
        int minDistance = INT_MAX;
        // Find the diff between every two consecutive values in the list.
        for (int i = 1; i < inorderNodes.size(); i++) {
            minDistance = min(minDistance, inorderNodes[i] - inorderNodes[i - 1]);
        }
        
        return minDistance;
    }
};
