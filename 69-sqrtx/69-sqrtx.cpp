class Solution {
public:
    int mySqrt(int x) {
        long long s = 0;
        long long l = x;
        long long ans;
        while(s <= l){
            long long m = s + (l - s)/2;
            if(m*m <= x){
                ans = m;
                s = m + 1; 
            }
            else{
                l = m - 1;
            }
        }
        return ans ;
    }
};