class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.length() < ransomNote.length()) return false;
        unordered_map<char, int> map;
        for(int i = 0; i < magazine.length(); i++){
            if(map.find(magazine[i]) != map.end()){
                map[magazine[i]]++;
            }
            else{
                map[magazine[i]] = 1;
            }
        }
        for(int i = 0; i < ransomNote.length(); i++){
            if(map.find(ransomNote[i]) == map.end()) return false;
            else{
                if(map[ransomNote[i]] == 0) return false;
                map[ransomNote[i]]--;
            }
        }
        return true;
    }
};