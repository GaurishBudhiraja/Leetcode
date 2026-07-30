class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> res(n);
        sort(nums1.begin(),nums1.end());
        vector<pair<int,int>> b;
        for(int i=0;i<n;i++){
            b.push_back({nums2[i],i});
        }
        sort(b.begin(),b.end());
        int l=0,r=n-1;
        for(int a : nums1){
            if(a > b[l].first){
                res[b[l].second] = a;
                l++;
            }else{
                res[b[r].second] = a;
                r--;
            }
        }
        return res;
    }
};