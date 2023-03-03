class Solution {
public:
    vector<int> computeLPSArray(string pattern){
        int m = pattern.length();
        int i = 0, j = 1;
        vector<int> lps(m);
        lps[0] = 0;
        while(j < m){
            if(pattern[i] == pattern[j]){
                lps[j] = i + 1;
                j++;
                i++;
            }
            else{
                if(i != 0){
                    i = lps[i - 1];
                }
                else{
                    lps[j] = 0;
                    j++;
                }
            }
        }
        return lps;
    }
    
    int strStr(string haystack, string needle) {
        if(needle.length() == 0) return 0;
        vector<int> lps = computeLPSArray(needle);
        int i = 0, j = 0;
        int n = haystack.length();
        int m = needle.length();
        while(i < n){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }
            else{
                if(j != 0){
                    j = lps[j - 1];
                }
                else{
                    i++;
                }
            }
            if(j == m){
                return (i - j);
            }
        }
        return -1;
    }
};