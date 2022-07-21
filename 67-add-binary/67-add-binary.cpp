class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();
        int i = n - 1;
        int j = m - 1;
        string ans = "";
        char carry = '0';
        while(i >= 0 && j >= 0){
            if(a[i] == '0' && b[j] == '0'){
                ans = carry + ans;
                carry = '0';
                i--; j--;
            }
            else if(a[i] == '1' && b[j] == '1'){
                ans = carry + ans;
                carry = '1';
                i--; j--;
            }
            else{
                if(carry == '0'){
                    ans = '1' + ans;
                    carry = '0';
                    i--; j--;
                }
                else{
                    ans = '0' + ans;
                    carry = '1';
                    i--; j--;
                }
            }
        }
        
        while(i >= 0){
            if(a[i] == '0'){
                ans = carry + ans;
                carry = '0';
                i--;
            }
            else{
                if(carry == '0'){
                    ans = '1' + ans;
                    carry = '0';
                    i--;
                }
                else{
                    ans = '0' + ans;
                    carry = '1';
                    i--;
                }
            }
        }
        
        while(j >= 0){
            if(b[j] == '0'){
                ans = carry + ans;
                carry = '0';
                j--;
            }
            else{
                if(carry == '0'){
                    ans = '1' + ans;
                    carry = '0';
                    j--;
                }
                else{
                    ans = '0' + ans;
                    carry = '1';
                    j--;
                }
            }
        }
        if(carry == '1') ans = '1' + ans;
        return ans;
    }
};