class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> hashMap;
        for(int i = 0; i < 26; i++){
            hashMap[order[i]] = i;
        }
        for(int i = 1; i < words.size(); i++){
            int j = 0;
            int n = min(words[i-1].size(), words[i].size());
            bool flag = true;
            while(j < n){
                if(hashMap[words[i-1][j]] < hashMap[words[i][j]]) {
                    flag = false;
                    break;
                }
                else if(hashMap[words[i-1][j]] > hashMap[words[i][j]]) return false;
                j++;
            }
            if(flag && words[i-1].size() > words[i].size()) return false;
        }
        return true;
    }
};