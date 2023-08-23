//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int>>ans;
            int n=grid.size();
    int m=grid[0].size();
    if(word.size()==1){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string str="";
                 str+=grid[i][j];
                 if(str==word){
                     vector<int>temp(2,0);
                     temp[0]=i;
                     temp[1]=j;
                     ans.push_back(temp);
                 }
            }
        }
        return ans;
    }
 
    int dx[8]={-1,-1,-1,0,1,+1,+1,0};
    int dy[8]={-1,0,1,1,1,0,-1,-1};
 
    set<pair<int,int>>temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int r=0;r<8;r++){
            string str="";
            str+=grid[i][j];
            int x1=i;
            int y1=j;
                while(x1<n&&y1<m&&x1>=0&&y1>=0){
                    x1+=dx[r];
                    y1+=dy[r];
                    if(x1<n&&y1<m&&x1>=0&&y1>=0){
                        str+=grid[x1][y1];
                    }
                    else{
                        break;
                    }
                    if(str.size()!=word.size()){
                        continue;
                    }
                      if(str==word){
                        temp.insert({i,j});
                       // break;
                    }
                   
                }
            }
        }
    }
    while(!temp.empty()){
        auto it=*(temp.begin());
        vector<int> t(2,0);
        t[0]=it.first;
        t[1]=it.second;
        temp.erase(it);
        ans.push_back(t);
    }
    if(ans.size()==0){
       return {{-1}};
    }
    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends