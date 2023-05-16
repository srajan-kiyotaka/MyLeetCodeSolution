//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Approach Using a hash and a queue
		    string ans;
		    // Hash
		    int arr[26] = {0};
		    // Queue
		    queue<char> q;
		    // Iterate over the Stream
		    for(int i = 0; i < A.length(); i++){
		        // Increment the frequency.
		        arr[A[i] - 'a']++;
		        // Push in the queue
		        q.push(A[i]);
		        // Check
		        if(arr[q.front() - 'a'] == 1){
		            ans.push_back(q.front());
		        }
		        else{
		            while(!q.empty() && arr[q.front() - 'a'] != 1){
		                q.pop();
		            }
		            if(q.empty()) ans.push_back('#');
		            else ans.push_back(q.front());
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends