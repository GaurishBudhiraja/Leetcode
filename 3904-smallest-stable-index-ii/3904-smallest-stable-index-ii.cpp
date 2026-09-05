class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size(),mn=INT_MAX,mx=INT_MIN;
        vector<int> suf(n,0);
        for(int i=n-1;i>=0;i--){
            mn=min(mn,nums[i]);
            suf[i]=mn;
        }
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            int sc=mx-suf[i];
            if(sc <= k) return i;
        }
        return -1;
    }
};