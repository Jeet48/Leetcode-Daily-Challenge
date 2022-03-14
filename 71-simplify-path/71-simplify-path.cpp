class Solution {
public:
    string simplifyPath(string path) 
    {
        vector<string> res;
        int i=0;
        while(i<path.length()) 
        {
    
            if (path[i] != '/') 
            {
                string s = "";
                while (i < path.length() && path[i] != '/') 
                    s+=path[i++];
                if(s == "..")
                {
                    if(res.size())
                        res.pop_back();
                }
                else if (s != ".") 
                    res.push_back(s);
            }
            else 
                ++i;
        }
        string ans="";
        for(string j : res) 
            ans = ans + "/"+ j;
        return !ans.length() ? "/" :ans;
    }
};