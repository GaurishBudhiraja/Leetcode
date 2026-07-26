class Solution {
public:
    struct cmp{
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        unordered_map<string,int>mp;
        for(string s : words){
            mp[s]++;
        }
        for(auto &it : mp){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};