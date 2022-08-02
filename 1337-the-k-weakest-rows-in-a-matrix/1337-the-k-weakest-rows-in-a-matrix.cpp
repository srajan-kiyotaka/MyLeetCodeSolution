class Solution {
public:
        static bool sortcol(vector<int>& v1,
                     vector<int>& v2){
            return (v1[0] == v2[0])?(v1[1] < v2[1]):(v1[0] < v2[0]);
        }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> result;
        vector<int> ans;
        for(int i = 0; i < mat.size(); i++){
            int temp = 0;
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] == 0) break;
                temp++;
            }
            result.push_back({temp, i});
        }
        
        sort(result.begin(), result.end(), sortcol);
        
        for(int i = 0; i < k; i++){
            ans.push_back(result[i][1]);
        }
        return ans;
    }
};