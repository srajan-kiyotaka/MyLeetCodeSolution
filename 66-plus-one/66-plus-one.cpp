class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--){
            if(i == 0){
                if(carry != 0){
                    if(carry + digits[i] > 9){
                        digits[i] += carry;
                        carry = digits[i] / 10;
                        digits[i] %= 10;
                        digits.insert(digits.begin(), carry);
                        return digits;
                    }
                    else{
                        digits[i] = digits[i] + carry;
                        return digits;
                    }
                }
                else{
                    return digits;
                }
            }
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        return digits;
    }
};