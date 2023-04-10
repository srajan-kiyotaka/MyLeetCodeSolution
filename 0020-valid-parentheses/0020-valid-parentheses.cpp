class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stk.push(s[i]);
            }
            else{
                if(stk.empty()) return false;
                char curr = stk.top();
                if((curr == '(' && s[i] == ')') || (curr == '[' && s[i] == ']') || (curr == '{' && s[i] == '}')){
                    stk.pop();
                }
                else return false;
            }
        }
        if(stk.empty()) return true;
        return false;
    }
};