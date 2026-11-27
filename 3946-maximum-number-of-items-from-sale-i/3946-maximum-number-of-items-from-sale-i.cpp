class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& it,int b){
        int c[1501]={};
        for(auto& i:it){
            int fac=i[0];
            for(int f=1;f<=1500;f++){
                if(fac%f==0) c[f]++;
            }
        }
        vector<int> dp(b+1,0);
        for (auto& i:it){
            int f=i[0],p=i[1];
            vector<int> ndp=dp;
            for(int j=b;j>=p;j--) ndp[j]=max(ndp[j],dp[j-p]+c[f]);
            for(int j=p;j<=b;j++) ndp[j]=max(ndp[j],ndp[j-p]+1);
            dp=move(ndp);
        }
        return *max_element(dp.begin(), dp.end());
    }
};