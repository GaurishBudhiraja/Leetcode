class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        int mx=INT_MIN;
        for(auto &it:mp){
            mx=max(mx,it.second);
        }
        int c=0;
        for(auto &it:mp){
            if(it.second == mx){
                c+=mx;
            }
        }
        return c;
    }
};