class Solution {
public:
    int balancedStringSplit(string s) {
        int result = 0;
        int Lcount = 0;
        int Rcount = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'R'){
                Rcount++;
                if(Rcount == Lcount){
                    result++;
                    Rcount = 0;
                    Lcount = 0;
                }
            }
            else if(s[i] == 'L'){
                Lcount++;
                if(Rcount == Lcount){
                    result++;
                    Lcount = 0;
                    Rcount = 0;
                }
            }
        }
        return result;
    }
};