class Solution {
public:
    int lengthOfLastWord(string s) {
        string token;
        istringstream ss(s);
        vector<string> split;
        while(getline(ss, token, ' ')){
            split.push_back(token);
        }
        int i = split.size() - 1;
        while(i >= 0){
            if(split[i].length() != 0){
                return split[i].length();
            }
            i--;
        }   

        return 0;
    }
};