class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string ans = (i > j)? num1 : num2;
        int k = ans.length() - 1;
        while(i >= 0 && j >= 0){
            int temp = (num1[i--] - '0') + (num2[j--] - '0') + carry;
            carry = temp / 10;
            ans[k--] = '0' + (char)(temp % 10);
            }
        while(carry != 0 && k >= 0){
            int t = (int)(ans[k] - '0') + carry;
            ans[k] = '0' + (char)(t % 10);
            carry = t / 10;
            k--;
        }
        // cout << carry << endl;
        if(carry != 0){
            ans = to_string(carry) + ans;
        }
        return ans;
    }
};