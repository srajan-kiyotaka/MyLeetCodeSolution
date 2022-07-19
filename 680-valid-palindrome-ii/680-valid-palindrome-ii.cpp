class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while(l <= r){
            if(s[l] != s[r]){
                string left, right, rleft, rright;
                left = s.substr(l, (r - l));
                rleft = left;
                right = s.substr(l + 1, (r - l));
                rright = right;
                reverse(left.begin(), left.end());
                reverse(right.begin(), right.end());
                if(left.compare(rleft) == 0 ||
                   right.compare(rright) == 0) return true;
                return false;
            }
            l++; r--;
        }
        return true;
    }
};