class Solution {
public:
    int largestInteger(int num) {
       string x = to_string(num);
        
        vector<char> odd,even;
        
        for(int i=0;i<x.size();i++)
        {
           if((x[i]-'0')%2)
               odd.push_back(x[i]);
            else
                even.push_back(x[i]);
        }
        
        int i=0,j=0;
        
        sort(odd.begin(),odd.end());
        reverse(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        reverse(even.begin(),even.end());
        
        string ans;
        
        for(int k=0;k<x.size();k++)
        {
              if((x[k]-'0')%2)
               ans+=odd[i++];
            else
                ans+=even[j++];
        }
        
        return stoi(ans);
    }
};