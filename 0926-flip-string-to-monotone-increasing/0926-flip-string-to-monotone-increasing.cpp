class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flipAns = 0;
        int one = 0;
        for(char a : s){
            if(a == '1'){
                one++;
            }
            else if(one > 0){
                flipAns++;
                one--;
            }
        }
        return flipAns;
    }
};