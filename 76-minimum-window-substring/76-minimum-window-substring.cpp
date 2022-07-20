class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> maps2;
        string ans;
        for(int i = 0; i < t.length(); i++){
            if(maps2.find(t[i]) != maps2.end()){
                maps2[t[i]]++;
            }
            else{
                maps2[t[i]] = 1;
            }
        }
        unordered_map<char, int> maps1;
        int i = 0, j = 0;
        int match = 0;
        int prefmatch = t.length();
        while(true){
            bool flag1 = false, flag2 = false;
            
            // accuare
            while(i < s.length() && match < prefmatch){
               if(maps1.find(s[i]) != maps1.end()){
                    maps1[s[i]]++;
                }
                else{
                    maps1[s[i]] = 1;
                }
                if(maps2.find(s[i]) != maps2.end()){
                    if(maps2[s[i]] >= maps1[s[i]]) match++;
                }
                i++;
                flag1 = true;
            }
            string res ;
            while(j < i && match == prefmatch){
                
                res = s.substr(j, i - j);
                if(ans.length() == 0 || ans.length() > res.length()){
                    ans = res;
                }
                maps1[s[j]]--;
                if(maps2.find(s[j]) != maps2.end()){
                    if(maps1[s[j]] < maps2[s[j]]){
                        match--;
                    }
                }
                j++;
                flag2 = true;
            }
            
            if(flag1 == false && flag2 == false){break;}
            
        }
        
        // if(ans.length() == 0) return "-1";
        return ans;
    }
};