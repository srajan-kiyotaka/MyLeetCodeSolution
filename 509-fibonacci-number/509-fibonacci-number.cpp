class Solution {
public:
    int fib(int n) {
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