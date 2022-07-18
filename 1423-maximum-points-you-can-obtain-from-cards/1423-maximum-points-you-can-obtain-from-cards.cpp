class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int size = cardPoints.size();
        for(int i= 0; i < size; i++){
            sum += cardPoints[i];
        }
        if(size == k) return sum;
        int window = 0;
        for(int i = 0; i < size - k - 1; i++){
            window += cardPoints[i];
        }
        int ans = sum;
        for(int i = size - k - 1; i < size; i++){
            window += cardPoints[i];
            ans = min(ans, window);
            window -= cardPoints[i - size + k + 1];
        }
        return sum - ans;
    }
};