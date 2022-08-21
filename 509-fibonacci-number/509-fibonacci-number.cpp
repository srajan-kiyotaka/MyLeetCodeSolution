class Solution {
public:
    unordered_map<int, int> map;
    int f(int n){
        if(n < 2) return n;
        if(map.find(n) != map.end()) return map[n];
        map[n] = f(n - 1) + f(n - 2);
        return map[n];
    }
    
    int fib(int n) {
        map[0] = 0;
        map[1] = 1;
        map[2] = 1;
        return f(n);
        if(n == 0) return 0;
        if(n == 1) return 1;
        int ans = 1, temp = 0;
        for(int i = 1; i < n; i++){
            int t = ans;
            ans = ans + temp;
            temp = t;
        }
        return ans;
    }
};