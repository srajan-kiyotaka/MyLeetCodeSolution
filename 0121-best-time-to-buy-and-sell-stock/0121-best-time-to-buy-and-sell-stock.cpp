class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;
        int size = prices.size();
        int temp;
        for(int i = 0; i < size; i++){
            if(prices[i] < mini) mini = prices[i];
            if(profit < (prices[i] - mini)) profit = prices[i] - mini;
        }
        
        return profit;
    }
};