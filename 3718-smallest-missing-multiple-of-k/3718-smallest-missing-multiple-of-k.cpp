class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s(nums.begin(),nums.end());
        int c=k;
        while(s.count(c)){
            c+=k;
        }
        return c;
    }
};