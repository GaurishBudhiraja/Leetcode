class Solution {
public:
    int stoneGameV(vector<int>& s) {
        int n=s.size();
        vector<int> pre(n+1,0);
        for(int i = 0; i < n; i++){
            pre[i+1]=pre[i]+s[i];
        }
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=2;i<=n;i++){
            for(int j=0;j+i<=n;j++){
                int r=j+i-1;
                for(int k=j;k<r;k++){
                    int left = pre[k+1]-pre[j];
                    int right = pre[r+1]-pre[k+1];
                    if(left<right){
                        dp[j][r] = max(dp[j][r],left + dp[j][k]);
                    }else if(right<left){
                        dp[j][r] = max(dp[j][r],right+dp[k+1][r]);
                    }else{
                        dp[j][r] = max(dp[j][r],left+max(dp[j][k],dp[k+1][r]));
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};