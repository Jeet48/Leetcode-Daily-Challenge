class Solution {
public:
    unordered_map<int, int> mp;
    vector<vector<int>> ans;
    vector<int> curr;
    
    
    void permutation(int idx,vector<int> &nums)
    {
        
      int n = nums.size();        

      if(idx==n)
      {
          ans.push_back(curr);
          return;
      }
        for(auto &k: mp){
            int key = k.first;
            int val = k.second;
            
            if(val==0) continue;
            
            curr.push_back(key);
            mp[key]--;
            permutation(idx+1,nums);
            curr.pop_back();
            mp[key]++;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(auto &k: nums) mp[k]++;
        permutation(0,nums);
        
        return ans;
    }
};