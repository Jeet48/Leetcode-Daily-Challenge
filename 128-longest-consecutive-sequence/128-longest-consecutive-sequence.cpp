class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> S;
        int ans = 0;
        
        for(int i = 0; i<nums.size() ;i++)
        {
            S.insert(nums[i]);
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(S.find(nums[i]-1) == S.end())
            {
                int j = nums[i];
                while (S.find(j) != S.end())
                    j++;
                
                ans = max(ans, j- nums[i]);
            }
        }
        return ans;
    }
};