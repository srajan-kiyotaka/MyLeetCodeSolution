//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool checkPalindrome(string a, string b){
        int n = a.length();
        for(int i = 0; i < n; i++){
            if(a[i] != b[n - i - 1]) return false;
        }
        return true;
    }
    
    bool checkWordPalindrome(string s){
        int n = s.length();
        int i = 0;
        int j = n - 1;
        while(j > i){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    
    bool makePalindrome(int n,vector<string> &arr){
        // each pair of the string must be a pallindrome
        if(n & 1){
            int count = 0;
            while(arr.size() > 0){
                string a = arr[0];
                arr.erase(arr.begin());
                bool flag = true;
                n = arr.size();
                for(int j = 0; j < n; j++){
                    if(checkPalindrome(a, arr[j])){
                        arr.erase(arr.begin() + j);
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    if(count == 0) {
                        count++;
                        if(!checkWordPalindrome(a)) return false;
                    }
                    else return false;
                }
            }
            
            // for(int i = 0; i < n; i++){
            //     if(arr[i] == "NULL") continue;
            //     else{
            //         bool flag = true;
            //         for(int j = 0; j < n; j++){
            //             if(i == j) continue;
            //             if(checkPalindrome(arr[i], arr[j])){
            //                 arr[i] = "NULL";
            //                 arr[j] = "NULL";
            //                 flag = false;
            //                 break;
            //             }
            //         }
            //         if(flag){
            //             if(count == 0) {
            //                 count++;
            //                 if(checkWordPalindrome(arr[i])) arr[i] = "NULL";
            //                 else return false;
            //             }
            //             else return false;
            //         }
            //     }
            // }
        } 
        else{
            while(arr.size() > 0){
                string a = arr[0];
                arr.erase(arr.begin());
                bool flag = true;
                n = arr.size();
                for(int j = 0; j < n; j++){
                    if(checkPalindrome(a, arr[j])){
                        arr.erase(arr.begin() + j);
                        flag = false;
                        break;
                    }
                }
                if(flag) return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends