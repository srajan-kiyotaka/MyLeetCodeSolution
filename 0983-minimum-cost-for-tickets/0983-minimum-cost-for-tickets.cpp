class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        if(days.size() == 1) return min(costs[0], min(costs[1], costs[2]));
        // DP
        int totalDays = days.size();
        int lastDay = days.back();
        vector<int> dp(lastDay+1, 0);
        unordered_set<int> travelDays;
        for(int i = 0; i < totalDays; i++){
            travelDays.insert(days[i]);
        }
        for(int i = 1; i <= lastDay; i++){
            if(travelDays.find(i) != travelDays.end()){
                dp[i] = min(dp[i-1]+costs[0], min(dp[max(0, i-7)]+costs[1], dp[max(0, i-30)]+costs[2]));
            }
            else{
                dp[i] = dp[i-1];
            }
        }
        return dp[lastDay];
    }
};
