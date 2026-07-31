class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        string t="";
        for(int i=0;i<nums.size();i++){
            int j=i;
            while(j+1<nums.size() && nums[j+1] == nums[j]+1){
                j++;
            }
            if(j>i){
                t+=to_string(nums[i]);
                t+="->";
                t+=to_string(nums[j]);
            }else{
                t+=to_string(nums[i]);
            }
            res.push_back(t);
            t="";
            i=j;
        }
        return res;
    }
};