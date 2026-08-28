class Solution {
public:
    void dfs(vector<vector<int>>& g,vector<int>& v,int i){
        v[i]=1;
        for(int j=0;j<g.size();j++){
            if(g[i][j] && !v[j])
                dfs(g,v,j);
        }
    }
    int findCircleNum(vector<vector<int>>& g){
        int n=g.size(),c=0;
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            if(!v[i]){
                c++;
                dfs(g,v,i);
            }
        }
        return c;
    }
};