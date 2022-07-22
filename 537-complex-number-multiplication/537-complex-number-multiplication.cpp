class Solution {
public:
    vector<int> complex(string num){
        istringstream ss(num);
        vector<string> split;
        vector<int> ans;
        string token;
        while(getline(ss, token, '+')){
            split.push_back(token);
            // cout << token << endl;
        }
        // cout << split.size() << endl;
        split[1].pop_back();
        ans.push_back(stoi(split[0]));
        ans.push_back(stoi(split[1]));
        return ans;
    }
    string complexNumberMultiply(string num1, string num2) {
        vector<int> ans1 = complex(num1);
        vector<int> ans2 = complex(num2);
        int real = ans1[0]*ans2[0] - ans1[1]*ans2[1];
        int img = ans1[0]*ans2[1] + ans1[1]*ans2[0];
        string ans = to_string(real);
        ans = ans + "+" + to_string(img) + "i";
        return ans;
    }
};