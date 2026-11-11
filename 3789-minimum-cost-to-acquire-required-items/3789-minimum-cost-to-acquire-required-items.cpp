class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c=min(costBoth,cost1+cost2);
        long long ans=(long long)min(need1,need2)*c;
        int rem1=need1-min(need1,need2);
        int rem2=need2-min(need1,need2);
        ans+=(long long)rem1*min(costBoth,cost1);
        ans+=(long long)rem2*min(costBoth,cost2);
        return ans;
    }
};