class Solution {
public:
    string simplifyPath(string path) {
        vector<string> split;
        string ans = "";
        istringstream ss(path);
        string token;
        while(getline(ss, token, '/')){
            split.push_back(token);
        }
        stack<string> st;
        for(auto i : split){
            if(i == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else if(i != "" && i != "."){
                st.push(i);
            }
        }
        if(st.empty()){
            return "/";
        }
        else{
            string temp = "";
            
            while(!st.empty()){
                temp = "/" + st.top();
                ans = temp + ans;
                st.pop();
            }
        }
        return ans;
    }
};