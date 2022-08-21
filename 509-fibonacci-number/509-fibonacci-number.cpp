class Solution {
public:
    int f(int n){
        if(n < 2) return n;
        return f(n - 1) + f(n - 2);
    }
    
    int fib(int n) {
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