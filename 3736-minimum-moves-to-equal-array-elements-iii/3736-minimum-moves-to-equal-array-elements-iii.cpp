class Solution {
public:
    int minMoves(vector<int>& nums) {
        int c=0,mx=*max_element(nums.begin(),nums.end());
        for(int n:nums){
            c+= mx-n;
        }
        return c;
    }
};