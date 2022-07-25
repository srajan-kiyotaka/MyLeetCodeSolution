class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> st1;
        stack<int> st2;
        vector<int> prev_smallest(n);
        vector<int> next_smallest(n);
        for(int i = 0; i < n; i++){
            prev_smallest[i] = i;
            next_smallest[i] = n - i - 1;
        }
        for(int i = 0; i < n; i++){
            
            while(!st1.empty() && arr[st1.top()] > arr[i]){
                next_smallest[st1.top()] = i - st1.top() - 1;
                st1.pop();
            }
            st1.push(i);
        }
        
        for(int i = n - 1; i >= 0; i--){
            
            while(!st2.empty() && arr[st2.top()] >= arr[i]){
                prev_smallest[st2.top()] = st2.top() - i - 1;
                st2.pop();
            }
            st2.push(i);
        }
        long long ans = 0;
        long long parameter = 1e9+7;
        for(int i = 0; i < n; i++){
            ans += (long long)(prev_smallest[i] + 1)*(next_smallest[i] + 1)*arr[i];
            ans = ans % parameter;
        }
        
        return ans;
    }
};