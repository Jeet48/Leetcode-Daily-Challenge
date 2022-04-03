class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;
        for(i=n-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
                break;
        }
        if(i==0)
        {
            sort(nums.begin(),nums.end());
            return;
        }
        
        int x = i-1;
        int j = n-1;
        while(x<j)
        {
            if(nums[x]<nums[j])
                break;
            j--;
        }
        sort(nums.begin()+i, nums.begin()+j+1);
        swap(nums[i-1],nums[i]);
        sort(nums.begin()+i,nums.end());
        
    }
};