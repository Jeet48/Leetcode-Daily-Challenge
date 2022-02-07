class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
          vector<vector<int> > ans;
		// & if there are less than 3 elements in our array, then no triplet is possible
		// so, return that empty ans vector
        if(nums.size()<3)return ans;
		// otherwise, sort the array, so that we can use two pointer approach
        sort(nums.begin(), nums.end());
		// let our leftmost pointer is i
		// and size of array is n
        int i=0, n=nums.size();
		// i can start from 0 and maximum go till n-3
        while(i<(n-2)){
			// now, we will use two pointer approach to find for remaining two pinters on the basis of this first pointer
			// j will start from i+1 and k will start from end of array
			// we will consider -ve of nums[i] as our target for two pointer approach, so that all three values sum up to give zero
            int j=i+1, k=n-1, target=(-1)*nums[i];
            
            while(j<k){
                int s=nums[j]+nums[k];
                // if our two pointer sum is less than the target, then we need to increase our sum and that can be done by increasing j
                if(s<target){
					j++;
				}
				// if our two pointer sum is greater than the target, then we need to increase our sum and that can be done by increasing j
                else if(s>target){
					k--;
				}
                else{
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    ans.push_back(tmp);
					
                    j++;
                    k--;
                    
					// but we have to take care of duplicates also
					// so, we will ignore same values of nums[j], nums[k]
                    while(j<k && nums[j]==nums[j-1])j++;
                    while(k>j && nums[k]==nums[k+1])k--;
                }
            }
            i++;
			// we have to ignore duplicate values of i also
            while(i<nums.size() && nums[i]==nums[i-1])i++;
        }
		// finally, return ans vector
        return ans;
    }
};