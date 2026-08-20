class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> s1,s2;
        s1.push_back(nums[0]);
        s2.push_back(nums[1]);
        for(int i=2;i<n;i++){
            if(s1.back()>s2.back()) s1.push_back(nums[i]);
            else s2.push_back(nums[i]);
        }
        vector<int> res;
        res.insert(res.end(),s1.begin(),s1.end());
        res.insert(res.end(),s2.begin(),s2.end());
        return res;
    }
};