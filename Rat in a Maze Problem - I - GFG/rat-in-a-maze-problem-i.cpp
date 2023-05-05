//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void findAllPaths(vector<vector<int>> &m, vector<string> &ans, string path, int n, int curr_x, int curr_y){
        if(curr_x >= n || curr_y >= n) return;
        if(m[curr_x][curr_y] == 0) return;
        if(curr_x == n - 1 && curr_y == n - 1){
            ans.push_back(path);
            return;
        }
        
        if(curr_y - 1 >= 0){
            if(m[curr_x][curr_y - 1] == 1){
                m[curr_x][curr_y] = -1;
                path.push_back('L');
                findAllPaths(m, ans, path, n, curr_x, curr_y - 1);
                path.pop_back();
                m[curr_x][curr_y] = 1;
            }
            
        }
        if(curr_y + 1 < n){
            if(m[curr_x][curr_y + 1] == 1){
                m[curr_x][curr_y] = -1;
                path.push_back('R');
                findAllPaths(m, ans, path, n, curr_x, curr_y + 1);
                path.pop_back();
                m[curr_x][curr_y] = 1;
            }
        }
        if(curr_x - 1 >= 0){
            if(m[curr_x - 1][curr_y] == 1){
                m[curr_x][curr_y] = -1;
                path.push_back('U');
                findAllPaths(m, ans, path, n, curr_x - 1, curr_y);
                path.pop_back();
                m[curr_x][curr_y] = 1;
            }
        }
        if(curr_x + 1 < n){
            if(m[curr_x + 1][curr_y] == 1){
                m[curr_x][curr_y] = -1;
                path.push_back('D');
                findAllPaths(m, ans, path, n, curr_x + 1, curr_y); 
                path.pop_back();
                m[curr_x][curr_y] = 1;
            }
        }
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Using recursion
        vector<string> ans;
        string path;
        findAllPaths(m, ans, path, n, 0, 0);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends