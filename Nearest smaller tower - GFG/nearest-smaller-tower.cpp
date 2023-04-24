//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        vector<int>prev, next;
        stack<int>st;
        
        for(int i=0; i<arr.size(); i++){
            
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                prev.push_back(-1);
            }
            else{
                prev.push_back(st.top());
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for (int i = arr.size() - 1; i >= 0; i--){
            
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
            next.push_back(-1);
        else
            next.push_back(st.top());
            
        st.push(i);
    }
    
    reverse(next.begin(), next.end());

    vector<int> ans;
    for (int i = 0; i < arr.size(); i++){
        
        // Neither left nor right
        if (prev[i] == -1 && next[i] == -1)
            ans.push_back(-1);
            
        else if (prev[i] == -1)
            ans.push_back(next[i]);
            
        else if (next[i] == -1)
            ans.push_back(prev[i]);
            
        else
        {
            if (i - prev[i] == next[i] - i)
            {
                if (arr[prev[i]] <= arr[next[i]])
                    ans.push_back(prev[i]);
                else
                    ans.push_back(next[i]);
            }
            else if (i - prev[i] < next[i] - i)
            {
                ans.push_back(prev[i]);
            }
            else
            {
                ans.push_back(next[i]);
            }
        }
    }
    return ans;
       
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends