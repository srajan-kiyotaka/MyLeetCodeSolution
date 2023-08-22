//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > a, int n)
    {
         int ans=0,cnt=0;
        vector<int>row(n,0);
        vector<int>col(n,0);
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=a[i][j];
            }row[i]=sum,cnt=max(cnt,sum);
        }
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=a[j][i];
            }col[i]=sum,cnt=max(cnt,sum);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int add=min(cnt-row[i],cnt-col[j]);
                row[i]+=add;
                col[j]+=add;
                ans+=add;
            }
        }
        return ans;
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends