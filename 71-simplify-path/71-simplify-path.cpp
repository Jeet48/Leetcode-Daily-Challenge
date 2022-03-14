class Solution {
public:
    string simplifyPath(string path) {
      if(path.back() != '/')
          path +="/";
        int n = path.size();
        string ans, temp;
        for(int i=0; i<n; i++) {

            if(path[i] != '/')
                temp.push_back(path[i]);
            else{
                if(temp == ".."){
                    while(!ans.empty() && ans.back() != '/') ans.pop_back();
                    if(!ans.empty())
                        ans.pop_back();
                }
                else if(!temp.empty() && temp!=".")
                    ans+="/"+temp;
                temp=""; 
            }
        }
        if(ans.empty())
            ans="/";
        return ans;
    }
};