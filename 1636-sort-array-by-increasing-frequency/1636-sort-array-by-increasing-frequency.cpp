class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums){
        unordered_map<int,int>mp;
        for(int num : nums){
            mp[num]++;
        }
        vector<pair<int,int>> v;
        for(auto &it : mp){
            v.push_back({it.first, it.second});
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> res;
        for(auto &it : v){
            while(it.second > 0){
                res.push_back(it.first);
                it.second--;
            }
        }
        return res;
    }
};