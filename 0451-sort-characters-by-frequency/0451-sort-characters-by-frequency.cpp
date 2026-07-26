class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>>pq;
        string res="";
        for(char c : s){
            mp[c]++;
        }
        for(auto &it : mp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            res.append(pq.top().first,pq.top().second);
            pq.pop();
        }
        return res;
    }
};