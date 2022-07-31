/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        deque<Node*> dq;
        dq.push_front(root);
        while(!dq.empty()){
            int len = dq.size();
            for(int i = 0; i < len; i++){
                Node* temp = dq.front();
                dq.pop_front();
                if(temp->left != NULL){
                    dq.push_back(temp->left);
                }
                if(temp->right != NULL){
                    dq.push_back(temp->right);
                }
                if(i == len - 1){
                    temp->next = NULL;
                    break;
                }
                temp->next = dq.front();
            }
        }
        return root;
    }
};