//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Greedy Approach
        vector<pair<double, Item>> sack;
        for(int i = 0; i < n; i++){
            sack.push_back(make_pair((((double)arr[i].value)/((double)arr[i].weight)), arr[i]));
        }
        // sort the sack array
        sort(sack.begin(), sack.end(), [&](pair<double, Item> &a, pair<double, Item> &b){
            return (a.first > b.first);
        });
        double ans = 0;
        int i = 0;
        while(W > 0 && i < n){
            ans += sack[i].first*min(W, sack[i].second.weight);
            W = W - min(W, sack[i].second.weight);
            i++;
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends