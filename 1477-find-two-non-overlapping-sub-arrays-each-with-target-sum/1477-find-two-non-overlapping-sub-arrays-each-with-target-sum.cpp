class Solution {
public:
    int minSumOfLengths(vector<int>& arr,int target){
        int n=arr.size(),l=0,sum=0,ans=INT_MAX,prev=INT_MAX;
        vector<int> b(n,INT_MAX);
        for(int r=0;r<n;r++){
            sum+=arr[r];
            while(sum>target){
                sum-=arr[l++];
            }
            if(sum==target){
                int len = r-l+1;
                if(l>0 && b[l-1]!=INT_MAX)
                    ans = min(ans,len+b[l-1]);
                prev=min(prev,len);
            }
            b[r]=prev;
        }
        return ans==INT_MAX?-1:ans;
    }
};