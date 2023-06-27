//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node{
public:
    char c;
    int val;
    Node* left;
    Node* right;
    Node(char c, int val, Node* left, Node* right){
        this->c = c;
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

class Compare{
public:
    bool operator()(Node* a, Node* b){
        return (a->val > b->val);
    }
};


Node* buildHuffmanTree(string S,vector<int> f,int N){
    // Approach: Using Min Heap 
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    for(int i = 0; i < N; i++){
        minHeap.push(new Node(S[i], f[i], NULL, NULL));
    }
    // create the tree
    while(minHeap.size() != 1){
        Node* l = minHeap.top();
        minHeap.pop();
        Node* r = minHeap.top();
        minHeap.pop();
        minHeap.push(new Node('#', l->val + r->val, l, r));
    }
    return minHeap.top();
}

void preorderTraversal(Node* root, vector<string> &ans, string code = ""){
    // Base Case
    if(root->c != '#'){
        ans.push_back(code);
        return;
    }
    // go left
    preorderTraversal(root->left, ans, code + '0');
    // go right
    preorderTraversal(root->right, ans, code + '1');
}


class Solution
{   
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Step 1: First build the huffman Tree.
		    Node* root = buildHuffmanTree(S, f, N);
		    vector<string> ans;
		    preorderTraversal(root, ans);
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends