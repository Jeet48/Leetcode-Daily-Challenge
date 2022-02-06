class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     const int n = nums.size();
	int hole = 0, idx=0; // two pointers 

	while( idx < n ){ // iterating the array

		int start = nums[idx];
		nums[hole++] = start; // filling the hole once

		int cnt = 0;
		while( idx+1 < n and nums[idx+1] == nums[idx] ) {
			idx++;
			cnt++;
		}

		if( cnt ) nums[hole++] = start; // if the cnt > 0 then we put two elements in the hole
		idx++;
	}

	return hole;

    }
};