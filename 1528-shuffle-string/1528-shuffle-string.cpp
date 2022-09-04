class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string suff = s;
        for(int i = 0; i < s.length(); i++){
            suff[indices[i]] = s[i];
        }
        return suff;
    }
};