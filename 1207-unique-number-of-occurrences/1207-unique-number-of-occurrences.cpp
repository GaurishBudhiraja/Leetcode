class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int num : arr){
            mp[num]++;
        }
        unordered_set<int> freq;
        for(auto p : mp){
            if(freq.count(p.second)){
                return false;
            }
            freq.insert(p.second);
        }
        return true;
    }
};