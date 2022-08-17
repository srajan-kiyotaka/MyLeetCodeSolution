class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 1) return false;
        while(n > 0){
            // cout << n << endl;
            if(n != 1 && n % 4 != 0) return false;
            n /= 4;
        }
        return true;
    }
};