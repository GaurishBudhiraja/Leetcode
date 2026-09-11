class Solution {
public:
    int dfs(vector<vector<int>> &g,vector<bool> &vis,int f){
    auto ch=0;
    vis[f]=true;
    for(auto to:g[f]){
        if(!vis[abs(to)]){
            ch += dfs(g,vis,abs(to))+(to>0);
        }
    }
    return ch;        
    }
    int minReorder(int n,vector<vector<int>>& co){
        vector<vector<int>>g(n);
        for(auto &c : co){
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(-c[0]);
        }
        return dfs(g,vector<bool>(n)={},0);
    }
};