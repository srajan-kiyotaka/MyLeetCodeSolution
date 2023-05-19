//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&vec1, int q, vector<int>vec2){
        sort(vec1.begin(),vec1.end());
        int start=vec1[0][0],end=vec1[0][1];
        vector<vector<int>> vec;
        for(int i=1;i<n;i++){
            if(vec1[i][0]<=end){
                if(end<vec1[i][1]) end=vec1[i][1];
            }
            else{
                vec.push_back({start,end});
                start=vec1[i][0];end=vec1[i][1];
            }
        }
        vec.push_back({start,end});
        vector<int> res;
        for(int i=0;i<q;i++){
            int k=vec2[i];
            bool find=false;
            for(int j=0;j<vec.size();j++){
                start=vec[j][0];end=vec[j][1];
                if(k<=end-start+1){
                    res.push_back(start+k-1);
                    find=true;
                    break;
                }
                else{
                    k=k-(end-start+1);
                }
            }
            if(find==false){
                res.push_back(-1);
            }
        }
        return res;
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
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends