class Solution {
public:
    const long long M1=1000000007;
    const long long M2=1000000009;
    const long long B=131;
    vector<long long> h1,h2,p1,p2;
    bool check(int len) {
        unordered_map<unsigned long long,int> mp;
        int n=h1.size()-1;
        for(int i=0;i+len<=n;i++) {
            int j=i+len;
            long long a=(h1[j]-h1[i]*p1[len]%M1+M1)%M1;
            long long b=(h2[j]-h2[i]*p2[len]%M2+M2)%M2;
            unsigned long long key=(a<<32)|b;
            mp[key]++;
        }
        for(auto x:mp) if(x.second==1) return true;
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        h1.resize(n+1);
        h2.resize(n+1);
        p1.resize(n+1);
        p2.resize(n+1);
        p1[0]=p2[0]=1;
        for(int i=0;i<n;i++) {
            h1[i+1]=(h1[i]*B+nums[i])%M1;
            h2[i+1]=(h2[i]*B+nums[i])%M2;
            p1[i+1]=p1[i]*B%M1;
            p2[i+1]=p2[i]*B%M2;
        }
        int l=1,r=n,ans=n;
        while(l<=r) {
            int mid=l+(r-l)/2;
            if(check(mid)) {
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};