class Solution {
public:
    int calPoints(vector<string>& ops) {
          stack<int> st;
        int x;
        int y;
        int ans = 0;
        
        for(auto value : ops)
        {
            if(value=="C")
            {
                st.pop();
            }
            else if(value=="D")
            {
                st.push(st.top()*2);
            }
            else if(value=="+")
            {
                x = st.top();
                st.pop();
                y = x + st.top();
                st.push(x);
                st.push(y);
            }
            else
            {
                st.push(stoi(value));
            }
        }
        
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        
        return ans;
        
    }
};