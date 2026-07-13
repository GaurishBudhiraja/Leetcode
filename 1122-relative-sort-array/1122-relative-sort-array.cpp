class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        unordered_map<int,int> mp;
        for(int num : arr1){
            mp[num]++;
        }
        for(int num : arr2){
            while(mp[num]>0) {
                res.push_back(num);
                mp[num]--;
            }
        }
        vector<int> asc;
        for(auto &it : mp){
            while(it.second > 0){
                asc.push_back(it.first);
                it.second--;
            }
        }
        sort(asc.begin(),asc.end());
        for(int num : asc){
            res.push_back(num);
        }
        return res;
    }
};