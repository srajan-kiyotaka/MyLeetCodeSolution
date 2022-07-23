class Solution {
    map<pair<long long, long long>, pair<long long, long long>> dp;
public:
    // pair<max_leaf, product>
    pair<long long, long long> calculate(int start, int end, vector<int>& arr){
        if(start == end){
            dp[{start, end}] = {arr[start], 0};
            return {arr[start], 0};
        }
        if(dp.find({start, end}) != dp.end()){
            return dp[{start, end}];
        }
       
        long long min_sum = INT_MAX;
        long long max_leaf = INT_MIN;
        for(int i = start; i < end; i++){
            auto left = calculate(start, i, arr);
            auto right = calculate(i+1, end, arr);
            max_leaf = max(left.first, right.first);
            min_sum = min(min_sum, left.second + right.second + left.first*right.first);
        }
        dp[{start, end}] = {max_leaf, min_sum};
        return {max_leaf, min_sum};
        
    }
    int mctFromLeafValues(vector<int>& arr) {
        auto ans = calculate(0, arr.size() - 1, arr);
        return ans.second;
    }
};