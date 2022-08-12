class Solution {
public:
    unordered_map<int, int> map;
    
    int climbStairs(int n){
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(map.find(n) != map.end()) return map[n];
        int ans = 0;
        
        if(n > 0){
            ans += climbStairs(n - 1);
            ans += climbStairs(n - 2);
        }
        map[n] = ans;
        return ans;
    }
};