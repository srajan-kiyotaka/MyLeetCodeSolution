class Solution {
public:
    vector<vector<string>> result;

    bool checkPalindrome(string& s, int start, int end){
        while(end > start){
            if(s[end--] != s[start++]) return false;
        }
        return true;
    }

    void backtrackingFun(string& s, vector<string> palindrome, int start){
        if(start >= s.size()){
            result.push_back(palindrome);
            return;
        }
        for(int i = start; i < s.size(); i++){
            if(checkPalindrome(s, start, i)){
                palindrome.push_back(s.substr(start, i - start + 1));
                backtrackingFun(s, palindrome, i + 1);
                palindrome.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> p;
        backtrackingFun(s, p, 0);
        return result;  
    }
};