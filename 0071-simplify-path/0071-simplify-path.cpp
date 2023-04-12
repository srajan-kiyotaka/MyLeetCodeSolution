class Solution {
public:
    string simplifyPath(string path) {
        path.push_back('/');
        // Using stack 
        stack<string> s;
        string folder = "";
        for(int i = 1; i < path.length(); i++){
            if(path[i] != '/'){
                folder += path[i];
            }
            else{
                if(folder.length() == 0){
                    continue;
                }
                else if(folder == "."){
                    folder = "";
                    continue;
                }
                else if(folder == ".."){
                    if(!s.empty()){
                        s.pop();
                    }
                }
                else{
                    s.push(folder);
                }
                folder = "";
            }
        }
        path = "";
        while(!s.empty()){
            folder = s.top();
            s.pop();
            if(path.length() == 0){
                path = folder;
            }
            else{
                path = folder + '/' + path;
            }
        }
        path = '/' + path;
        return path;
    }
};