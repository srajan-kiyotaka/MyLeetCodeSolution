class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        if(numRows < 1) return pascal;
        pascal.push_back({1});
        
        for(int i = 1; i < numRows; i++){
            vector<int> temp(i + 1);
            int k = -1;
            // cout
            for(int j = 0; j <= pascal[i-1].size(); j++, k++){
                // cout << j << " " ;
                if(k == -1){
                    // cout << "crazy" << endl;
                    temp[0] = 1;
                }
                else if(j == pascal[i-1].size()){
                    // cout << "crazy" << endl;
                    temp[j] = 1;
                    break;
                }
                else{
                    temp[j] = pascal[i-1][k] + pascal[i-1][j];
                }
                
            }
            // cout << endl;
            pascal.push_back(temp);
        }
        return pascal;
    }
};