class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n) return *max_element(nums.begin(),nums.end());
        if(k == 1){
            unordered_map<int,int>mp;
            for(int num : nums){
                mp[num]++;
            }
            int res=-1;
            for(auto& p : mp){
                if(p.second==1){
                    res=max(res,p.first);
                }
            }
            return res;
        }
        bool firstDuplicate = false;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[0]){
                firstDuplicate=true;
                break;
            }
        }
        bool lastDuplicate=false;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[n-1]){
                lastDuplicate = true;
                break;
            }
        }
        if (firstDuplicate && lastDuplicate) return -1;
        if (!firstDuplicate && lastDuplicate) return nums[0];
        if (firstDuplicate && !lastDuplicate) return nums[n-1];
        return max(nums[0], nums[n-1]);
    }
};