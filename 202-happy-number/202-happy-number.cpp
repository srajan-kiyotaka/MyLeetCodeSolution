class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        s.insert(n);
        int temp = 0;
        while(n != 1){
            while(n > 0){
                temp += (n % 10) * (n % 10);
                n = n / 10;
            }
            n = temp;
            temp = 0;
            if(s.find(n) != s.end()){
                return false;
            }
            else{
                s.insert(n);
            }
        }
        return true;
    }
};