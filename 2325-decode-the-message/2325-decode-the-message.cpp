class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> hash_map;
        
        int count = 0;
        
        for(int i = 0; i < key.length() && count < 26; i++){
            if(key[i] != ' '){
                if(hash_map.find(key[i]) == hash_map.end()){
                    hash_map[key[i]] = 'a' + count;
                    count++;
                }
            }
        }
        
        for(int i = 0; i < message.length(); i++){
            if(message[i] != ' '){
                message[i] = hash_map[message[i]];
            }
        }
        
        return message;
    }
};