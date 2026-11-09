class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arr,vector<int>& load){
        set<int>s;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> b(k,0);
        for(int i=0;i<k;i++) s.insert(i);
        for(int i=0;i<arr.size();i++){
            while(!pq.empty() && pq.top().first<=arr[i]){
                s.insert(pq.top().second);
                pq.pop();
            }
            if(s.empty()) continue;
            auto it=s.lower_bound(i%k);
            if(it==s.end()) it=s.begin();
            int id=*it;
            s.erase(it);
            b[id]++;
            pq.push({arr[i]+load[i],id});
        }
        int mx=*max_element(b.begin(),b.end());
        vector<int> ans;
        for(int i=0;i<k;i++) if(b[i]==mx) ans.push_back(i);
        return ans;
    }
};