class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        unordered_map<char,int> map;
        for(int i = 0; i < stones.length(); i++){
            map[stones[i]]++;
        }
        for(int i = 0; i < jewels.length(); i++){
            ans += map[jewels[i]];
        }
        return ans;
    }
};