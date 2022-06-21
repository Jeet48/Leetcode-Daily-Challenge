class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> p;
        for(int i = 0;i < nums.size(); i++)
        {
            p[nums[i]] += 1;
            if(p[nums[i]]>1){
                return true;
            }
        }
        return false;
    }
};