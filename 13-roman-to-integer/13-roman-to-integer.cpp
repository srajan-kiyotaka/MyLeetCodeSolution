class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> map;
        map["I"] = 1;
        map["V"] = 5;
        map["X"] = 10;
        map["L"] = 50;
        map["C"] = 100;
        map["D"] = 500;
        map["M"] = 1000;
        map["IV"] = 4;
        map["IX"] = 9;
        map["XL"] = 40;
        map["XC"] = 90;
        map["CD"] = 400;
        map["CM"] = 900;
        
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            if(map.find(s.substr(i, 2)) != map.end()){
                ans += map[s.substr(i, 2)];
                i++;
            }
            else{
                ans += map[s.substr(i, 1)];
            }
        }
        
        return ans;
    }
};