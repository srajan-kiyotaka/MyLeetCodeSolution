//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    vector<vector<bool>>vis;
    int dx[4] = { 0 , -1 , 0 , 1};
    int dy[4] = {1 , 0 , -1 , 0};
    bool dfs(int x , int y , int index , int n  , int m , string word , 
    vector<vector<char>>& board){
        //base case
        if(index == word.length()){
            return true;
        }
        vis[x][y] = true;
        for(int i = 0; i<4 ;i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(newx >= 0 and newx < n and newy >= 0 and newy < m and !vis[newx][newy] 
                and board[newx][newy] == word[index]){
                    bool temp = dfs(newx , newy , index + 1, n , m , word , board);
                    if(temp == true)
                        return true;
                }
        }
        vis[x][y] = false;
        return false;
        
    }
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vis.resize(n , vector<bool>(m , 0));
        for(int i= 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == word[0]){
                    bool ans = dfs(i , j , 1 , n , m , word, board);
                    if(ans == true)
                        return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends