class Solution {
    static bool comparator(vector<int>& a,vector<int>& b)
    {

    return a[1]-a[0]>b[1]-b[0];
    }
public:
    int twoCitySchedCost(vector<vector<int>>& cost){
        int n = cost.size();
        sort(cost.begin(),cost.end(),comparator);
        int ans=0;
        for(int i=0;i<n;i++)
            ans+= i>=n/2?cost[i][1]:cost[i][0];
        
        return ans;
    }
};