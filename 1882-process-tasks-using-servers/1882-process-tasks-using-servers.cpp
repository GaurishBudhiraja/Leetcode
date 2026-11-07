class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size(),m=tasks.size();
        vector<int> res(m);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> free;
        priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>, greater<pair<long long,pair<int,int>>>> busy;
        for(int i=0;i<n;i++) free.push({servers[i],i});
        long long t=0;
        for(int i=0;i<m;i++){
            t=max(t,(long long)i);
            while(!busy.empty() && busy.top().first<=t){
                auto p=busy.top();
                busy.pop();
                free.push({p.second.first,p.second.second});
            }
            if(free.empty()){
                t=busy.top().first;
                while(!busy.empty() && busy.top().first<=t){
                    auto p=busy.top();
                    busy.pop();
                    free.push({p.second.first, p.second.second});
                }
            }
            auto p=free.top();
            free.pop();
            res[i]=p.second;
            busy.push({t+tasks[i],{p.first, p.second}});
        }
        return res;
    }
};