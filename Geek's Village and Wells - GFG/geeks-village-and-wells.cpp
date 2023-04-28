//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool inrange(int i, int j, int n, int m) {
		if (i < 0 || i >= n || j < 0 || j >= m) {
			return false;
		}
		return true;
	}
	vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &c) {
		int dx[] = {1 , 0, -1, 0};
		int dy[] = {0 , 1, 0, -1};
		vector<vector<int>>res(n, vector<int>(m, -1));
		queue<pair<pair<int, int>, int>>q;
		vector<vector<bool>>vis(n,vector<bool>(m,false));
		for (int i =  0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (c[i][j] == 'W') {
					q.push({{i, j}, 0});
					res[i][j] = 0;
				}
			}
		}
		while (!q.empty()) {
			int sz = q.size();
			for (int i = 0 ; i < sz; i++) {
				auto x = q.front();
				q.pop();
				int u = x.first.first;
				int v = x.first.second;
				int dis = x.second;
				for (int j = 0; j < 4; j++) {
					int newx = u + dx[j];
					int newy = v + dy[j];
					if (inrange(newx, newy, n, m) && c[newx][newy] != 'N' && !vis[newx][newy] && c[newx][newy]!='W') {
						q.push({{newx, newy}, dis + 2});
						res[newx][newy] = dis + 2;
						vis[newx][newy] = true;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (c[i][j] != 'H') {
					res[i][j] = 0;
				}
			}
		}
		return res;
	}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends