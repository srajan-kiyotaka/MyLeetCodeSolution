class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                char c = st.top();
                st.pop();
                if((c == '(' && s[i] != ')') || (c == '{' && s[i] != '}') || (c == '[' && s[i] != ']')){
                   return false; 
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
};