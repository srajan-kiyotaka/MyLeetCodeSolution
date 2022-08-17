class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map;
        vector<string> words;
        set<string> done;
        string token;
        stringstream temp(s);
        while(getline(temp, token, ' ')){
            // cout<< token << endl;
            words.push_back(token);
        }
        
        if(words.size() != pattern.length()) return false;
        
        for(int i = 0; i < pattern.length(); i++){
            if(map.find(pattern[i]) != map.end()){
                if(map[pattern[i]] != words[i]) return false;
                done.insert(words[i]);
                continue;
            }
            if(done.find(words[i]) != done.end()) return false;
            map[pattern[i]] = words[i];
            done.insert(words[i]);
        }
        
        return true;
    }
};