class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> n1,n2,res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) n1.push_back(nums[i]);
            else n2.push_back(nums[i]);
        }    
        int i=0,j=0;
        while(i<n1.size() && j<n2.size()){
            res.push_back(n1[i++]);
            res.push_back(n2[j++]);
        }
        return res;
    }
};