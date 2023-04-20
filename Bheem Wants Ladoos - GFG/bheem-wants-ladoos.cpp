//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    unordered_map<Node*, Node*> parent;
    
    void getParent(Node* root, int home, Node* &source, Node* par)
    {
        if(!root) return ;
        parent[root] = par;
        if(root-> data == home ) 
            source= root;
            
        getParent(root->left, home , source, root);
        getParent(root->right, home, source, root);
        
    }
    
    int ladoos(Node* root, int home, int k)
    {
        Node* source=NULL;
        getParent(root,home,source, NULL);
        
        queue<Node*> Q;
        Q.push(source);
        int ans=0;
        unordered_set<Node*> ust;
        ust.insert(source);
        while(Q.size())
        {
            int size= Q.size();
            for(int i=0;i< size;i++)
            {
                Node* cur= Q.front();
                Q.pop();
                ans+= cur-> data;
                // cout<<cur-> data<<" ";
                
                if(cur->left && ust.count(cur->left)==0)
                {
                    Q.push(cur->left);
                    ust.insert(cur->left);
                }
                if(cur->right && ust.count(cur->right) ==0 )
                {
                    Q.push(cur->right);
                    ust.insert(cur->right);
                }
                if(parent[cur] && ust.count(parent[cur])==0)
                {
                    Q.push(parent[cur]);
                    ust.insert( parent[cur]);
                }
            }
            if(k==0) break;
            k--;
        }
        return ans;
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends