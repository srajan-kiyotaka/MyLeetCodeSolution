class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size());
        int maxi = 0;
        for(int i = 0; i < candies.size(); i++){
            if(maxi < candies[i]) maxi = candies[i];
        }
        for(int i = 0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= maxi)
                result[i] = true;
            else
                result[i] = false;
        }
        return result;
    }
};