class Solution {
public:
    int dp(vector<vector<int>>& matrix, string& s, int i, int  j){
        if(i > j) return 0;
        if(i == j) return 1;
        if(matrix[i][j] != 0) return matrix[i][j];
        if(s[i] == s[j]){
            matrix[i][j] = dp(matrix, s, i+1, j-1) + 2;
        }
        else{
            matrix[i][j] = max(dp(matrix, s, i, j-1), dp(matrix, s, i+1, j));
        }
        return matrix[i][j];
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        return dp(matrix, s, 0, n-1);
    }
};

/*
    / Recurcive Brute Force /

    int longest = -1;

    int isPalin(string p){
        if(p.length() == 0) return -1;
        int i = 0;
        int j = p.length() - 1;
        while(i < j){
            if(p[i] != p[j]) return -1;
            i++;
            j--;
        }
        return p.length();
    }

    void helper(string s, string c = "", int i = 0){
        if(i == s.length()){
            // cout << c << endl;
            longest = max(longest, isPalin(c));
        }
        else{
            helper(s, c, i + 1);
            c.push_back(s[i]);
            helper(s, c, i + 1);
        }
    }


    int longestPalindromeSubseq(string s) {
        if(isPalin(s) == s.length()) return s.length();
        helper(s);
        return longest;
    }
*/