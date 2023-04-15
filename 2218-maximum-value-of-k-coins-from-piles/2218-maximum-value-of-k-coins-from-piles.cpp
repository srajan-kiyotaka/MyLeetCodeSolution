class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> memo(n + 1, vector<int>(k + 1, 0));
        function<int(int, int)> dp = [&](int i, int k) {
            if (memo[i][k] > 0) return memo[i][k];
            if (i == n || k == 0) return 0;
            int res = dp(i + 1, k), cur = 0;
            for (int j = 0; j < piles[i].size() && j < k; ++j) {
                cur += piles[i][j];
                res = max(res, dp(i + 1, k - j - 1) + cur);
            }
            memo[i][k] = res;
            return res;
        };
        return dp(0, k);
    }
};