class Solution {
public:
    int minimumSum(int num) {
        vector<int> digit;
        // int temp = 0;
        while(num > 0){
            digit.push_back(num%10);
            num /= 10;
        }
        sort(digit.begin(), digit.end());
        num = digit[0]*10 + digit[1]*10 + digit[2] + digit[3];
        return num;
    }
};