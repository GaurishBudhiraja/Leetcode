class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n=nums.size();
        multiset<int> l,r;
        long long s1=0,s2=0;
        vector<long long> cost(n-x+1);
        auto balance = [&](){
            while(l.size()>r.size()+1){
                int v = *l.rbegin();
                l.erase(prev(l.end()));
                s1 -= v;
                r.insert(v);
                s2 += v;
            }while(l.size()<r.size()){
                int v = *r.begin();
                r.erase(r.begin());
                s2 -= v;
                l.insert(v);
                s1 += v;
            }
        };
        for(int i=0;i<n;i++){
            int v=nums[i];
            if(l.empty() || v<=*l.rbegin()){
                l.insert(v);
                s1 += v;
            }else{
                r.insert(v);
                s2 += v;
            }
            if(i>=x){
                v=nums[i-x];
                if(l.find(v) != l.end()){
                    l.erase(l.find(v));
                    s1 -= v;
                }else{
                    r.erase(r.find(v));
                    s2 -= v;
                }
            }
            balance();
            if(i>=x-1){
                long long m = *l.rbegin();
                cost[i-x+1] = m*l.size()-s1+s2-m*r.size();
            }
        }
        const long long INF = LLONG_MAX/4;
        vector<long long> dp(n+1,0),ndp(n+1);
        for(int t=1;t<=k;t++){
            fill(ndp.begin(),ndp.end(),INF);
            for(int i=1;i<=n;i++){
                ndp[i] = ndp[i-1];
                if (i>=x && dp[i-x] != INF) ndp[i] = min(ndp[i],dp[i-x]+cost[i - x]);
            }
            dp.swap(ndp);
        }
        return dp[n];
    }
};