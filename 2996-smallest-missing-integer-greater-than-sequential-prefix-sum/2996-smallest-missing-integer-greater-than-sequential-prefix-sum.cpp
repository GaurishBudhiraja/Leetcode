class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] + 1 == nums[i]){
                sum+=nums[i];
            }else{
                break;
            }
        }
        while(find(nums.begin(),nums.end(),sum)!=nums.end()){
            sum++;
        }
        return sum;
    }
};