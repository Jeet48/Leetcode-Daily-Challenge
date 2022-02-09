class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        map <int,int> a;
        int l=0,r=1;                    //pointers
        sort(nums.begin(),nums.end());  //sorting in ascending
        while(l<nums.size()-1)
        {
            if(nums[r]-nums[l]==k)      //checking for condition
            {
                a[nums[l]]=nums[r];
                l++;r=l+1;
            }
            else if(nums[r]-nums[l]<k)  //incrementing the right pointer
            {
                r++;
            }
            else if(nums[r]-nums[l]>k)  //shifting the left pointer 
            {
                l++;r=l+1;
            }
            if(r==nums.size())          //incase right pointer goes out of bounds
            {
                l++;r=l+1;
            }
        }
        return a.size();
        
        
        
    }
};