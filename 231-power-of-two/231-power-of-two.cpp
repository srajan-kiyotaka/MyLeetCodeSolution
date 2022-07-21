class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long x = 1;
        if(n < 1) return false;
        while(n >= x){
            if(n == x) return true;
            x = 2*x;
        }
        return false;
    }
};