class Solution {
public:
    bool isPalindrome(string s) {
        // Two pointer approch
        int i = 0;
        int j = s.length() - 1;
        while(i < j && j >= 0){
            while(i < s.length() && !((tolower(s[i]) <= 'z' && tolower(s[i]) >= 'a') || (s[i] >= '0' && s[i] <= '9'))){i++;}
            while(j >= 0 && !((tolower(s[j]) <= 'z' && tolower(s[j]) >= 'a') || (s[j] >= '0' && s[j] <= '9'))){j--;}
            // cout << s[i] << ", " << s[j] << endl;
            if(i < j && j >= 0 && (tolower(s[i++]) != tolower(s[j--]))) return false;
        }
        return true;
    }
};