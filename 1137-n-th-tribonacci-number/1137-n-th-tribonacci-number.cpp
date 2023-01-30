class Solution {
public:
    unordered_map<int, int> hashMap;
    int tribonacci(int n) {
        hashMap[0] = 0;
        hashMap[1] = 1;
        hashMap[2] = 1;
        if(hashMap.find(n) != hashMap.end()) return hashMap[n];
        hashMap[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3); 
        return hashMap[n];
    }
};