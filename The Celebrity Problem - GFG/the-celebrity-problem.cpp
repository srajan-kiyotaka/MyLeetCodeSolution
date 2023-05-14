//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // Approach: Using Stack
        stack<int> stack;
        // Put all the people into the stack
        for(int i = 0; i < n; i++){
            stack.push(i);
        }
        // Check two people
        while(stack.size() != 1){
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            if(M[a][b]) stack.push(b);
            else stack.push(a);
        }
        // Potential celebrity
        int poss = stack.top();
        // all know him
        for(int i = 0; i < n; i++){
            if(poss != i && !M[i][poss]) return -1;
        }
        // he knows none
        for(int i = 0; i < n; i++){
            if(poss != i && M[poss][i]) return -1;
        }
        return poss;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends