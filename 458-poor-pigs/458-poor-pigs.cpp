class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pig = 0;
        while(pow(((minutesToTest/minutesToDie) + 1), pig)  < buckets) pig++;
        return pig;
    }
};