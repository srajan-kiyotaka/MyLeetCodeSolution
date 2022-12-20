class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        int count1 = 0;
        while(n != 0){
            count1 += n & 1;
            n = n >> 1;
            if(count1 > 1) return false;
        }
        return true;
    }
};