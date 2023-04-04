//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    int acount = 0;
    int bcount = 0;
    char prev = '*';

    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if(prev == ch) continue;
        
        if(ch == 'a') acount++;
        else bcount++;
        
        prev = ch;
    }

    return min(acount, bcount) + 1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends