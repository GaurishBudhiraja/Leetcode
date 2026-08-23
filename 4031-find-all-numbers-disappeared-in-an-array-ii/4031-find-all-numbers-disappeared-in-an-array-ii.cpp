class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        long long prev=(long long)lower-1;
        for(int x:nums){
            if(x<lower || x>upper) continue;
            if(x>prev+1){
                res.push_back({(int)prev+1,x-1});
            }
            prev=x;
        }
        if(prev<upper){
            res.push_back({(int)prev+1,upper});
        }
        return res;
    }
};