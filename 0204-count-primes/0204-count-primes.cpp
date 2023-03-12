class Solution {
public:
    int countPrimes(int n) {
        // Using Sieve of Eratosthenes Method
        if(n < 2) return 0;
        vector<bool> numbers(n, true);
        int ans = 0;
        for(int i = 2; i < n; i++){
            if(numbers[i]){
                ans++;
                int j = i*2;
                while(j < n){
                    numbers[j] = false;
                    j += i;
                }
            }
        }
        return ans; 
    }
};