class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid=nums[nums.size()/2],c=0;
        for(int x : nums){
            c += abs(x-mid);
        }
        return c;
    }
};