class Solution {
public:
    vector<int> ans;
    vector<vector<int>> g,ng;
    int last[26];
    void dfs(int u,vector<int>& parent,string& s) {
        int ch=s[u]-'a';
        int prev=last[ch];
        int p=prev;
        if(p==-1) p=parent[u];
        if(u!=0) ng[p].push_back(u);
        last[ch]=u;
        for(int v:g[u]) dfs(v,parent,s);
        last[ch]=prev;
    }
    int calc(int u){
        ans[u]=1;
        for(int v:ng[u]) ans[u]+=calc(v);
        return ans[u];
    }
    vector<int> findSubtreeSizes(vector<int>& parent,string s) {
        int n=parent.size();
        g.resize(n);
        ng.resize(n);
        ans.resize(n);
        fill(last,last+26,-1);
        for(int i=1;i<n;i++) g[parent[i]].push_back(i);
        dfs(0,parent,s);
        calc(0);
        return ans;
    }
};