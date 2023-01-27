class Solution {
public:
    unordered_set<string> hashSet;

    bool check(string word){
        if(word.length() == 0) return false;
        int n = word.length();
        bool flag = false;
        for(int i = 1; i < n; i++){
            if((hashSet.find(word.substr(0, i)) != hashSet.end()) && ((hashSet.find(word.substr(i, n - i)) != hashSet.end()) || check(word.substr(i, n - i)))){
                return true;
            }
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int m = words.size();
        vector<string> result;
        for(int i = 0; i < m; i++){
            hashSet.insert(words[i]);
        }
        for(int i = 0; i < m; i++){
            if(check(words[i])) result.push_back(words[i]);
        }
        return result;
    }
};