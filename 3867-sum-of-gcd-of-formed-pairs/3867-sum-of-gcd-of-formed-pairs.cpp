class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        int mx=0;
        for(int num : nums){
            mx = max(mx,num);
            res.push_back(gcd(num,mx));
        }
        sort(res.begin(),res.end());
        long long ans=0;
        int l=0,r=n-1;
        while(l<r){
            ans += gcd(res[l],res[r]);
            l++;
            r--;
        }
        return ans;
    }
};