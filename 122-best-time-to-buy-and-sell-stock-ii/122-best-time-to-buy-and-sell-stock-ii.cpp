class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = 0;
        int size = prices.size();
        if(size < 2) return 0;
        
        if(prices[0] < prices[1]){
            buy = prices[0];
        }
        for(int i = 1; i < size - 1; i++){
            if(prices[i] > prices[i-1] && prices[i] >= prices[i + 1]){
                profit += prices[i] - buy;
            }
            else if(prices[i] <= prices[i-1] && prices[i] < prices[i + 1]){
                buy = prices[i];
            }
        }
        if(prices[size - 1] > prices[size - 2]){
            profit += prices[size - 1] - buy;
        }
        return profit;
    }
};