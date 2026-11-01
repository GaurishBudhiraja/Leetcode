class Solution {
public:
    int minMoves(vector<int>& nums) {
        int c=0,mn=*min_element(nums.begin(),nums.end());
        for(int x:nums){
            c+=x-mn;
        }
        return c;
    }
};