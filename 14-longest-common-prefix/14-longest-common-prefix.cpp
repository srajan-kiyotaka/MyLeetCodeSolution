class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i = 0; i < strs[0].length(); i++){
            for(auto k : strs){
                if(i == k.length() || strs[0][i] != k[i]){
                    return ans;
                }
            }
            ans += strs[0][i];
        }
        return ans;
    }
};