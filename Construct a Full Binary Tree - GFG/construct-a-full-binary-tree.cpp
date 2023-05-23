//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        int i = 0,j = size-1;
        stack<Node*>s;
        while(j >= 0){
            Node* nw = new Node(pre[i]);
            nw->left = NULL,nw->right = NULL;
            s.push(nw);
            while(!s.empty() && j >= 0 && s.top()->data == preMirror[j]){
                j--;
                if(s.size() == 1){
                    break;
                }
                else{
                    Node* nw = s.top(); s.pop();
                    if(s.top()->left == NULL){
                        s.top()->left = nw;
                    }
                    else{
                        s.top()->right = nw;
                    }
                }
            }
            i++;
        }
        return s.top();
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends