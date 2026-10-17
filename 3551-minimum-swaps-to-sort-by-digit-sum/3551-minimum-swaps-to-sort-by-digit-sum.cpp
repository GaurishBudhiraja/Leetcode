
class Solution {
public:
    int digitSum(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums){
        vector<pair<int, int>>arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end(),[&](auto a,auto b){
            int x=digitSum(a.first);
            int y=digitSum(b.first);
            if (x!=y) return x<y;
            return a.first<b.first;
        });
        vector<bool> vis(nums.size(),false);
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(vis[i]||arr[i].second==i) continue;
            int j=i;
            int s=0;
            while(!vis[j]){
                vis[j]=true;
                j=arr[j].second;
                s++;
            }
            c+=s-1;
        }
        return c;
    }
};
