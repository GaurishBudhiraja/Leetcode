class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>dp;
        int c=1;
        for(int x:nums){
            int a=dp[x-1]+1;
            int b=dp[x]+1;
            dp[x]=max(dp[x],a);
            dp[x+1]=max(dp[x+1],b);
            c=max({c,dp[x],dp[x+1]});
        }
        return c;
    }
};