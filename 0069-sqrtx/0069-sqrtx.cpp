class Solution {
public:
    int mySqrt(int x) {
        // Binary Search Problem
        if(x == 1) return x;
        int s = 1;
        int e = x/2;
        int mid = s + (e - s)/2;
        int ans = 0;
        while(s <= e){
            if(mid > INT_MAX/mid){
                e = mid - 1;
                mid = s + (e - s)/2;
                continue;
            }
            if(mid*mid == x) return mid;
            if(mid*mid > x){
                e = mid - 1;
            }
            else{
                ans = mid;
                s = mid + 1;
            }
            mid = s + (e - s)/2;
        }
        return ans;
    }
};

// long long s = 0;
//         long long l = x;
//         long long ans;
//         while(s <= l){
//             long long m = s + (l - s)/2;
//             if(m*m <= x){
//                 ans = m;
//                 s = m + 1; 
//             }
//             else{
//                 l = m - 1;
//             }
//         }
//         return ans ;