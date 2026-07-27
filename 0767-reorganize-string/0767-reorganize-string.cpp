class Solution {
public:
    string reorganizeString(string s) {
        string res;
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>>pq;
        for(char c:s){
            mp[c]++;
        }
        for(auto &it : mp){
            pq.push({it.second,it.first});
        }
        pair<int,char> prev = {0,'#'};
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            res+=cur.second;
            cur.first--;
            if(prev.first>0){
                pq.push(prev);
            }
            prev=cur;
        }
        if(res.size() != s.size()) return "";
        return res;
    }
};