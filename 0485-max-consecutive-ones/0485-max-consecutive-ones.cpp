class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int k=0,c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                c++;
            }
            else{
                k=max(k,c);
                c=0;
            }
        }
        return max(k,c);
    }
};