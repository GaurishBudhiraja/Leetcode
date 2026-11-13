class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size(),r=n-1;
        long long ans=0,sum=0;
        deque<int> dq;
        for(int l=n-1;l>=0;l--){
            while(!dq.empty() && nums[dq.back()]<nums[l]){
                int j=dq.back();
                dq.pop_back();
                int r1=dq.empty()?r+1:dq.back();
                sum+=1LL*(r1-j)*(nums[l]-nums[j]);
            }
            dq.push_back(l);
            while(sum>k){
                sum-=nums[dq.front()]-nums[r];
                if(dq.front()==r) dq.pop_front();
                r--;
            }
            ans+=r-l+1;
        }
        return ans;
    }
};