class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size(),e=0,o=0;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0) e++;
            else o++;
        }
        if(e==n || o==n) return true;
        int mn = *min_element(nums1.begin(),nums1.end());
        if(mn%2==1) return true;
        return false;
    }
};