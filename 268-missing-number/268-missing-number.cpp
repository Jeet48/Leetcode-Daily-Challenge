class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n, mask = 0;
        
        for(int i = 0; i < n; i++)
        {
            ans ^= nums[i];
            mask ^=i;
        }
        ans = (ans^mask);
        
        
        return ans;
    }
};