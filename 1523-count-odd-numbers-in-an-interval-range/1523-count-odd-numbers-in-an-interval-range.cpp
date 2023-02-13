class Solution {
public:
    int countOdds(int low, int high) {
        int temp = high - low;
        return (low % 2 != 0 && temp % 2 == 0)?(temp - (temp/2)) + 1:(temp - (temp/2));
    }
};