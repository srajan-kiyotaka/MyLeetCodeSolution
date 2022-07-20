class Solution {
public:
    string res = "";
    vector<string> ans;
    
    void backtrack(int open,int close,int n){
        if(open == close && open == n){
            ans.push_back(res);
            // cout << res << endl;
            // res = "";
            return ;
        }
        if(open < n){
            res += "(";
            backtrack(open + 1, close, n);
            res.pop_back();
        }
        if(close < open){
            res += ")";
            backtrack(open, close + 1, n);
            res.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n);
        return ans;
    }
};