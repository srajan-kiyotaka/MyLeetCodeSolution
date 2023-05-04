class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qd, qr;
        int n = senate.size();
        for(int i = 0; i < n; i++){
            (senate[i] == 'D')?(qd.push(i)):(qr.push(i));
        }
        while(!qd.empty() && !qr.empty()){
            int id_r = qr.front();
            int id_d = qd.front();
            qr.pop();
            qd.pop();
            if(id_r > id_d){
                qd.push(id_d + n);
            }
            else{
                qr.push(id_r + n);
            }
        }
        return (!qr.empty())?("Radiant"):("Dire");
    }
};