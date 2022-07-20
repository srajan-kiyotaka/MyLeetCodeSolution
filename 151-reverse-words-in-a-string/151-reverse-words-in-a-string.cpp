class Solution {
public:
    string reverseWords(string s) {
        vector<string> split;
        string token;
        istringstream ss(s);
        while(getline(ss, token, ' ')){
            split.push_back(token);
        }
        reverse(split.begin(), split.end());
        string ans;
        bool flag = false;
        for(auto i : split){
            if(i != "" && i != " "){
                if(!flag){
                    ans = i;
                    flag = true;
                }
                else{
                    ans += " " + i;
                }
            }
                
                
        }
        return ans;
    }
};