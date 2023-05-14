//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  private:
  void nextSmallestElementIndex(int *heights, vector<int> &next, int n){
	// Using stack
	stack<int> s;
	s.push(n);
	
	for(int i = n - 1; i >= 0; i--){
		while(s.top() != n && heights[s.top()] >= heights[i]){
			s.pop();
		}
		next[i] = s.top();
		s.push(i);
	}
}

void prevSmallestElementIndex(int *heights, vector<int> &prev, int n){
	// Using stack
	stack<int> stack;
	stack.push(-1);
	for(int i = 0; i < n; i++){
		while(stack.top() != -1 && heights[stack.top()] >= heights[i]){
			stack.pop();
		}
		prev[i] = stack.top();
		stack.push(i);
	}
}

int maxRectangleAreaInHistogram(int *heights, int n){
	// Next Smallest Element Index
	vector<int> next(n, 0);
	nextSmallestElementIndex(heights, next, n);
	// Previous Smallest Element Index
	vector<int> prev(n, 0);
	prevSmallestElementIndex(heights, prev, n);
	// Iterate over to get the maximum area of the rectangle possible
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(ans, (heights[i]*(next[i] - prev[i] - 1)));
	}
	return ans;
}
  public:
    int maxArea(int mat[MAX][MAX], int n, int m) {
        // Approach Using Max Rectangle in a Histogram.
    	// Solve each sub problem.
    	int ans = maxRectangleAreaInHistogram(mat[0], m);
    	for(int i = 1; i < n; i++){
    		for(int j = 0; j < m; j++){
    			if(mat[i][j] != 0) mat[i][j] += mat[i-1][j];
    		}
    		ans = max(ans, maxRectangleAreaInHistogram(mat[i], m));
    	}
    	return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends