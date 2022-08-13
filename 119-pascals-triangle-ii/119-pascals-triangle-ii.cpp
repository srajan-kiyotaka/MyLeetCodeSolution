class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> f = {1};
        if(rowIndex == 0){
            return f;
        }
        
        for(int j = 1; j <= rowIndex; j++){
            int i = -1;
            vector<int> temp(j + 1);
            for(int k = 0; k <= j; k++, i++){
                if(i == -1){
                    temp[0] = 1;
                }
                else if(k == j){
                    // cout << "yooo" << endl;
                    temp[k] = 1;
                    break;
                }
                else{
                    temp[k] = f[i] + f[k];
                }
            }
            f = temp;
        }
        return f;
    }
};