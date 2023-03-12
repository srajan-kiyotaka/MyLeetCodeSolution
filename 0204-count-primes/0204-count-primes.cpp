class Solution {
public:
    int countPrimes(int n) {
        // return segmentedSieve(n);
        // Using Segment Sieve Method
        // Time Complexity : O(n*log(log n))
        // Space Complexity : O(square root n)
        if(n <= 2) return 0;
        if(n == 3) return 1;
        if(n < 6) return 2;
        if(n < 7) return 3;
        // We will only store the primes of the first segment.
        vector<int> primes;
        int root = sqrt(n) + 1;
        vector<bool> number(root, true);
        // Do Simple Sieve to find the primes lessthan root.
        for(int i = 2; i < root; i++){
            if(number[i]){
                primes.push_back(i);
                int j = i*2;
                while(j < root){
                    number[j] = false;
                    j += i;
                }
            }
        }
        
        // variable to store the answer
        int ans = primes.size();
        
        // Set the range of the segment.
        int low = root;
        int high = 2*root;
        
        // Now, Iterate over all the segment to get the primes.
        while(low < n && abs(low - n) > 1){
            // for the last case
            if(high >= n) high = n;

            // Reset all the nymbers as true.
            for(int i = 0; i < root; i++){
                number[i] = true;
            }

            // Now, mark all the number which comes in the table of the primes 
            for(int p : primes){
                int i = (low / p) * p;
                i = ((i >= low)?(i):(i + p)) - low;
                while(i < root){
                    number[i] = false;
                    i += p;
                }
            }

            // Now, iterate over all the numbers and count the primes amongs them
            for(int i = low; i < high; i++){
                if(number[i - low]){
                    ans++;
                }
            }

            // Update the Limits. 
            low = low + root;
            high = high + root; 
        }

        return ans; 
    }
};
/*

// Using Segment Sieve Method
        // Time Complexity : O(n*log(log n))
        // Space Complexity : O(square root n)
        if(n < 2) return 0;
        vector<int> primes;
        vector<bool> number(sqrt(n), true);
        int root = sqrt(n);
        for(int i = 2; i < root; i++){
            if(number[i]){
                primes.push_back(i);
                int j = i*2;
                while(j < root){
                    number[j] = false;
                    j += i;
                }
            }
        }

        int low = root;
        int high = low + root;
        
        while(low < n && abs(low - n) > 1){
            if(high >= n){
                high = n;
            }
            vector<int> numbers(root, true);
            for(int p : primes){
                if(p*2 >= high) break;
                int i = (low / p) * p;
                i = ((i >= low)?(i):(i + p)) - low;
                while(i < root){
                    numbers[i] = false;
                    i += p;
                }
            }
            for(int i = low; i < high; i++){
                if(numbers[i - low]){
                    primes.push_back(i);
                }
            }
            low = high;
            // high = (high + root - n < 0)? n : high + root;
            high = high + root; 
        }

        // for(int it : primes){cout << it << " " ;}
        // cout << endl;

        return primes.size(); 
    }


*/

/*

int countPrimes(int n) {
        // Using Sieve of Eratosthenes Method
        // Time Complexity : O(n*log(log n))
        // Space Complexity : O(n)
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

*/