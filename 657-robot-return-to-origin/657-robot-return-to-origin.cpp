class Solution {
public:
    bool judgeCircle(string moves) {
        int i = 0;
        int j = 0;
        for(int k = 0; k < moves.length(); k++){
            if(moves[k] == 'R'){
                j++;
            }
            else if(moves[k] == 'L'){
                j--;
            }
            else if(moves[k] == 'U'){
                i--;
            }
            else{
                i++;
            }
        }
        if(i == 0 && j == 0){
            return true;
        }
        return false;
    }
};