class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> cp(arr.begin(),arr.end());
        sort(cp.begin(),cp.end());
        unordered_map<int,int> mp;
        int r=1;
        for(int num : cp){
            if(mp.count(num) == 0){
                mp[num] = r;
                r++;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};