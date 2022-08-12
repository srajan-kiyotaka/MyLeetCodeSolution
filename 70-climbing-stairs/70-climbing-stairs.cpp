class Solution {
public:
    unordered_map<int, int> map;
    int clime(int n){
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(map.find(n) != map.end()) return map[n];
        int ans = 0;
        
        if(n > 0){
            ans += clime(n - 1);
            ans += clime(n - 2);
        }
        map[n] = ans;
        return ans;
    }
    int climbStairs(int n) {
        return clime(n);
    }
};