class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = INT_MIN;
        for(int i = 0; i < accounts.size(); i++){
            int temp = 0;
            for(int j = 0; j < accounts[0].size(); j++){
                temp += accounts[i][j];
            }
            maxi = max(maxi, temp);
        }
        return maxi;
    }
};