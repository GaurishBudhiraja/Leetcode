class Solution {
public:
    void dfs(vector<vector<int>>& r,vector<int>& vis,int i){
        vis[i]=1;
        for(int x:r[i]){
            if(!vis[x])
                dfs(r,vis,x);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& r){
        int n=r.size();
        vector<int> vis(n,0);
        dfs(r,vis,0);
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};