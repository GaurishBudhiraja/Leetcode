class Solution {
public:
    bool canFinish(int nc,vector<vector<int>>& pq){
        vector<vector<int>> g(nc);
        vector<int> pointed(nc,0);
        for(auto &p:pq){
            g[p[1]].push_back(p[0]);
            pointed[p[0]]++;
        }
        queue<int> q;
        for(int i=0;i<nc;i++){
            if(pointed[i]==0) q.push(i);
        }
        int c=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            c++;
            for(int v : g[u]){
                pointed[v]--;
                if(pointed[v]==0) q.push(v);
            }
        }
        return c==nc;
    }
};