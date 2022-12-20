class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        int ans = 0;
        bool flag = x < 0;
        x = flag ? -x : x; 
        while(x != 0){
            if(ans > INT_MAX / 10) return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return flag ? -ans : ans;
    }
};