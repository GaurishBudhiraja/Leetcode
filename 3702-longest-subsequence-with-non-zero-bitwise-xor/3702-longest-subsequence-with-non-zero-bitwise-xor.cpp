class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int c=0,n=nums.size();
        bool az=true;
        for(int num:nums){
            c^= num;
            if(num != 0) az = false;
        }
        if(az) return 0;
        return c == 0?n-1 : n;
    }
};