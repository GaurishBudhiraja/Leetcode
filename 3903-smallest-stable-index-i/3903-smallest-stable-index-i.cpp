class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size(),mn = INT_MAX,mx=0; 
        vector<int> suf(n,0);mn = INT_MAX; 
        for(int i=n-1;i>=0;i--){
            mn=min(mn,nums[i]);
            suf[i] = mn;
        }
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            int score = mx - suf[i];
            if (score <= k)return i;
        }
        return -1;
    }
};