class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int t) {
        sort(nums.begin(),nums.end());
        vector<int> in;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==t) in.push_back(i);
        }
        return in;
    }
};