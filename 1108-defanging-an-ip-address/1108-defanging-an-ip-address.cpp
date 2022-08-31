class Solution {
public:
    string defangIPaddr(string address) {
        vector<string> ans;
        string temp = "";
        for(int i = 0; i < address.length(); i++){
            if(address[i] == '.'){
                ans.push_back(temp);
                temp = "";
            }
            else{
                temp += address[i];
            }
        }
        ans.push_back(temp);
        address = ans[0];
        for(int i = 1;i < ans.size(); i++){
            address += "[.]" + ans[i];
        }
        return address;
    }
};