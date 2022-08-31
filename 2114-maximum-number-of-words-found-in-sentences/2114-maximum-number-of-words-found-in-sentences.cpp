class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = 0;
        for(string k : sentences){
            string token;
            stringstream s(k);
            vector<string> words;
            while(getline(s, token, ' ')){
                words.push_back(token);
            }
            if(maxi < words.size()) maxi = words.size();
        }
        return maxi;
    }
};