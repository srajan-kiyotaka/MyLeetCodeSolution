//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
void ums(int &sum, int &min_sum, bool &update){ // update_min_sum
        
        min_sum = sum;
        update = true;
    }
    
    void fun(int &sum, int &min_sum, bool &update, int &i, vector<int> &S){
        
        //
        while(sum > min_sum && i < S.size()){
            
            sum -= S[i];
            i += 1;
        }
        
        if(sum < min_sum){
            ums(sum, min_sum, update);
        }
    }
    
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        
        //
        int sum1, sum2, sum3;
        sum1 = sum2 = sum3 = 0;
        
        //
        int N = max(N1, max(N2, N3));
        
        for(int i=0; i<N; i++){
            
            if(i < N1) sum1 += S1[i];
            if(i < N2) sum2 += S2[i];
            if(i < N3) sum3 += S3[i];
        }
        
        //
        int min_sum = min(sum1, min(sum2, sum3));
        bool update = false;
        
        int i=0, j=0, k=0;
        
        do{
            update = false;
            
            if(sum1 > min_sum){
                fun(sum1, min_sum, update, i, S1);
            }
            
            if(sum2 > min_sum){
                fun(sum2, min_sum, update, j, S2);
            }
            
            if(sum3 > min_sum){
                fun(sum3, min_sum, update, k, S3);
            }
            
            
        }while(update);
        
        //
        return min_sum;
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends