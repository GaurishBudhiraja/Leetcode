
class Solution {
public:
    int minimumChanges(string s,int k) {
        int n=s.size(),INF=1e9;
        vector<vector<int>> v(n,vector<int>(n,INF));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int len=j-i+1;
                for(int d=1;d<len;d++){
                    if(len%d) continue;
                    int c=0;
                    for(int r=0;r<d;r++){
                        int l=i+r,rr=j-((len-1-r)%d);
                        while(l<rr){
                            if(s[l]!=s[rr]) c++;
                            l+=d;
                            rr-=d;
                        }
                    }
                    v[i][j]=min(v[i][j],c);
                }
            }
        }
        vector<vector<int>> dp(n+1,vector<int>(k+1,INF));
        dp[n][0]=0;
        for(int p=1;p<=k;p++){
            for(int i=n-2;i>=0;i--){
                for(int j=i+1;j<n;j++){
                    if(dp[j+1][p-1]!=INF) dp[i][p]=min(dp[i][p],v[i][j]+dp[j+1][p-1]);
                }
            }
        }
        return dp[0][k];
    }
};
