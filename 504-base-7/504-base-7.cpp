class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        string ans = "";
        bool flag = false;
        if(num < 0){
            num = -num;
            flag = true;
        }
        while(num > 0){
            ans = to_string(num % 7) + ans;
            num /= 7;
        }
        if(flag) ans = "-" + ans;
        return ans;
    }
};