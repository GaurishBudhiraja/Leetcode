class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        unordered_map<int,int> mp;
        for(int n:nums) mp[n]++;
        for(auto& m:mp){
            if(m.second > nums.size()/3){
                res.push_back(m.first);
            }
        }
        return res;
    }
};