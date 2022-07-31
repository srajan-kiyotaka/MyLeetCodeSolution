class Solution {
public:
    unsigned long long fact(int n){
        if(n == 0 || n == 1) return 1;
        unsigned long long ans = 1; 
        for(int i = 2; i <= n; i++){
            ans *= i;
        }
        return ans;
    }
    
    unsigned long long ncr(int n, int r){
        return (fact(n)/(fact(r)*fact(n-r)));
    }
    
    int numTrees(int n) {
        long C = 1;
        for (int i = 0; i < n; ++i) {
          C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int) C;
    }
};