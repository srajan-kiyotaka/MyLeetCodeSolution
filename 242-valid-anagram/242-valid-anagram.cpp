class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        if(s.length() != t.length()) return false;
        for(int i = 0; i < s.length(); i++){
            if(map.find(s[i]) == map.end()){
                map[s[i]] = 1;
            }
            else{
                map[s[i]]++;
            }
        }
        
        for(int i = 0; i < t.length(); i++){
            if(map.find(t[i]) == map.end()){
                return false;
            }
            else{
                if(map[t[i]] == 0) return false;
                map[t[i]]--;
            }
        }
        return true;
    }
};