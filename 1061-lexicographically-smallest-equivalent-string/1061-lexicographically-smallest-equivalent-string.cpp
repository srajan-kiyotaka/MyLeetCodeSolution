class Solution {
public:
    int dfs(vector<int>& alpha, int p){
        if(alpha[p] == p) return p;
        alpha[p] = dfs(alpha, alpha[p]);
        return alpha[p];
    }

    void update(int p, int q, vector<int>& alpha){
        p = dfs(alpha, p);
        q = dfs(alpha, q);
        if(p == q) return;
        if(p > q){
            alpha[p] = q;
        }
        else {
            alpha[q] = p;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr){
        vector<int> alpha(26);
        int n = s1.size();

        for(int i = 0; i < 26; i++){
            alpha[i] = i;
        }

        for(int i = 0; i < n; i++){
            int p = s1[i] - 'a';
            int q = s2[i] - 'a';
            update(p, q, alpha);
        }
        n = baseStr.size();
        for(int i = 0; i < n; i++){
            baseStr[i] = dfs(alpha, (baseStr[i] - 'a')) + 'a'; 
        }
        return baseStr;
    }
};