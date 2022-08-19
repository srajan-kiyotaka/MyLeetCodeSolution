class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> map;
        for(int i = 0; i < s.length(); i++){
            if(map.find(s[i]) == map.end()){
                map[s[i]] = 0;
            }
            map[s[i]]++;
        }
        for(int i = 0; i < t.length(); i++){
            if(map.find(t[i]) == map.end()){
                return t[i];
            }
            if(map[t[i]] == 0) return t[i];
            map[t[i]]--;
        }
        return 'a';
    }
};