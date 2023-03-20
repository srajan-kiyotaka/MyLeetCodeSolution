class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() == 1){
            if(flowerbed[0] == 1){
                return n == 0;
            }
            else{
                return n <= 1;
            }
        }
        for(int i = 0; i < flowerbed.size(); i++){
            // cout << "~> " << i << ", n = " << n << endl;
            if(i == 0){
                if((flowerbed[i] | flowerbed[i+1]) == 0){
                    n--;
                    flowerbed[i] = 1;
                }
            }
            else if(i == flowerbed.size() - 1){
                if((flowerbed[i-1] | flowerbed[i]) == 0){
                    n--;
                    flowerbed[i] = 1;
                }
            }
            else if(((flowerbed[i-1] | flowerbed[i]) | flowerbed[i+1]) == 0){
                n--;
                flowerbed[i] = 1;
            }
            if(n == 0) return true;
        }
        return (n <= 0);
    }
};