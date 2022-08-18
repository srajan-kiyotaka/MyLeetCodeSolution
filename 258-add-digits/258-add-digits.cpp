class Solution {
public:
    vector<int> digit(int n){
        vector<int> ans;
        while(n > 0){
            ans.push_back(n % 10);
            n /= 10;
        }
        return ans;
    }
    int addDigits(int num) {
        if(num / 10 == 0) return num;
        int result = 0;
        vector<int> temp = digit(num);
        while(temp.size() != 1){
            result = accumulate(temp.begin(), temp.end(), 0);
            temp = digit(result);
        }
        return result;
    }
};