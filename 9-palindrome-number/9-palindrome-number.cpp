class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long temp = 0;
        long long n = x;
        while(n > 0){
            temp *= 10;
            temp += n % 10;
            n /= 10;
        }
        if(temp == x) return true;
        return false;
    }
};