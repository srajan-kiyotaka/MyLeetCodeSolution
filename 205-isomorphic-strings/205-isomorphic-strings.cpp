class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, char> map;
        set<char> done;
        for(int i = 0; i < s.length(); i++){
            if(map.find(s[i]) == map.end()){
                // cout << "crazzy" << endl;
                if(done.find(t[i]) != done.end()) return false;
                map[s[i]] = t[i];
                done.insert(t[i]);
                continue;
            }
            if(map[s[i]] != t[i]) return false;
            // cout << "foo" << endl;
            // if(done.find(t[i]) != map[s[i]]) return false;
        }
        return true;
    }
};