class Solution {
public:
    string decode(string& s, int& i){
        string result;
        while(i < s.length() && s[i] != ']'){
            if(isdigit(s[i])){
                int k = 0;
                while(isdigit(s[i])){
                    k = k*10 + (s[i++] - '0');
                    // i++;
                }
                i++;
                string r = decode(s, i);
                // string ans = "";
                while(k-- > 0){
                    result += r;
                }
                i++;
            }
            else{
                result += s[i++];
            }
        }
        return result;
    }
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
};