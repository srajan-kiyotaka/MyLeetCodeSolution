class Solution {
public:
    /* Using Complement Method */
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int gMask = 0;
        // 1's Compliment
        int x = ~n;
        while(n != 0){
            gMask = gMask << 1;
            gMask = gMask | 1;
            n = n >> 1;
        }
        return (x & gMask);
    }
    
    /*
    
    if(n == 0) return 1;
        int ans = 1;
        while(ans <= n){
            ans *= 2;
        }
        return (ans - n - 1);

    */

    /* Using Mask and Not */
    // int bitwiseComplement(int n) {
    //     if(n == 0) return 1;
    //     int mask = 0;
    //     int complement = ~n;
    //     while(n != 0){
    //         mask = mask << 1;
    //         mask = mask | 1;
    //         n = n >> 1;
    //     }
    //     return (complement & mask);
    // }
    
};