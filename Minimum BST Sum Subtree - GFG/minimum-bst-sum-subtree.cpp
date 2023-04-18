//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int ans = INT_MAX;
    //pair<int , pair<int , int > > will contain data in this order -> bool  , max , min 
    pair<bool , pair<int , int > >  is_BST(Node *root){
        if(!root)return {true , {INT_MIN , INT_MAX}};
        pair<bool , pair<int , int > > left = is_BST(root->left);
        pair<bool , pair<int , int > > right = is_BST(root->right);
        int maxi , mini;
        bool temp;
        temp  = left.first & right.first;
        if(root->left){
            if(root->data > root->left->data){
                temp &= true;
            }else{
                temp = false;
            }
        }
        
        if(root->right){
            if(root->data < root->right->data){
                temp &= true;
            }else{
                temp = false;
            }
        }
        
        if(right.second.second > root->data){
            temp &= true;
        }else{
            temp = false;
        }
        
        if(left.second.first < root->data){
            temp &= true;
        }else{
            temp = false;
        }
        
        maxi = max(left.second.first , right.second.first);
        mini = min(left.second.second , right.second.second);
        maxi = max( maxi, root->data);
        mini = min(mini , root->data);
    
        return {temp , {maxi , mini}};
    }
    pair<int , int > solve(Node *root ,int  target){
        if(!root)return {0,0};
        pair<int , int > left = solve(root->left , target);
        pair<int , int > right = solve(root->right , target);
        int sum = left.first + right.first + root->data;
        int len = left.second + right.second + 1;
        // cout<<sum<<" -> "<<len<<" && ";
        if(sum == target && is_BST(root).first){
            // pair<bool , pair<int ,int >> 
            ans = min(ans , len);
        }
        return {sum , len};
    }
    int minSubtreeSumBST(int target, Node *root) {
        solve(root , target);
        if(ans == INT_MAX)return -1;
        return ans;
        // code here
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends