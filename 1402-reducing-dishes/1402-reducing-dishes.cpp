class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        /*
            Greedy Approch

        we sort the input array in decreasing order. Then, we
        iterate over the array and calculate the prefix sums of 
        the elements, adding each prefix sum to the result as long
        as it remains non-negative. If the prefix sum becomes
        negative at any point, we stop the iteration and return
        the current result.
        
        */
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        int n = satisfaction.size();
        int prefixSum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            // add to prefixsum
            prefixSum += satisfaction[i];
            if (prefixSum < 0) {
                break;
            }
            ans += prefixSum;
        }
        return ans;
    }
};