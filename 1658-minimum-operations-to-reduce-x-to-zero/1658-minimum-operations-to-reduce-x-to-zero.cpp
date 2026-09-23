class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size(),sum=0,k=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(nums[i]>x) k++;
        }
        if(sum<x || k==n) return -1;
        int target=sum-x;
        int l=0,ws=0,maxlen=-1;
        for(int i=0;i<n;i++){
            ws+=nums[i];
            while(ws>target){
                ws-=nums[l];
                l++;
            }
            if(ws==target) {
                maxlen=max(maxlen,i-l+1);
            }
        }
        if(maxlen == -1) return -1;
        return n-maxlen;
    }
};