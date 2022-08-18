class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char, int> map;
        map['a'] = 1; map['e'] = 1; map['i'] = 1;
        map['o'] = 1; map['u'] = 1;
        map['A'] = 1; map['E'] = 1; map['I'] = 1;
        map['O'] = 1; map['U'] = 1;
        int i = 0;
        int j = s.length() - 1;
        while(i < j){
            while(i < s.length() && map.find(s[i]) == map.end()){i++;}
            while(j >= 0 && map.find(s[j]) == map.end()){j--;}
            if(i >= j) return s;
            swap(s[i], s[j]);
            i++; j--;
        }
        return s;
    }
};