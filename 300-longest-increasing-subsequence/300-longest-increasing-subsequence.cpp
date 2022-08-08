class Solution {
public:
    int subseq(vector<int>& arr,int prev,int n, int dp[][2600], int len)
    {
      if(n==0)
      {
          return dp[prev][n] = 0;
      }
        if(dp[prev][n]!=-1)
        {
           return dp[prev][n];
        }
        if(prev==len+1 || arr[n-1]<arr[prev-1])
        {
          return dp[prev][n] = max(1+subseq(arr, n, n-1, dp, len),subseq(arr, prev, n-1, dp, len));
        }
       return dp[prev][n] = subseq(arr, prev, n-1, dp, len);
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev = nums.size()+1;
        int dp[2600][2600];
        memset(dp, -1,sizeof dp);
        return subseq(nums,prev,nums.size(), dp, nums.size());
    }
};