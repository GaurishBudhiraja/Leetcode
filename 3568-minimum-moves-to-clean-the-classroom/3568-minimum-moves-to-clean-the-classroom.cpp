class Solution {
public:
    int minMoves(vector<string>& g,int energy){
        int m=g.size(),n=g[0].size(),sx,sy,k=0;
        vector<vector<int>> id(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]=='S') sx=i,sy=j;
                if(g[i][j]=='L') id[i][j]=k++;
            }
        }
        int full=(1<<k)-1;
        int dr[]={-1,1,0,0},dc[]={0,0,-1,1};
        vector vis(m,vector(n,vector(energy+1,vector<bool>(1<<k,false))));
        queue<array<int,5>> q;
        q.push({sx,sy,energy,0,0});
        vis[sx][sy][energy][0]=true;
        while(!q.empty()){
            auto [r,c,e,mask,moves]=q.front();
            q.pop();
            if(mask==full) return moves;
            for(int d=0;d<4;d++){
                int nr=r+dr[d],nc=c+dc[d];
                if(nr<0||nc<0||nr>=m||nc>=n||g[nr][nc]=='X'||e==0) continue;
                int ne=e-1,nmask=mask;
                if(g[nr][nc]=='R') ne=energy;
                if(g[nr][nc]=='L') nmask|=1<<id[nr][nc];
                if(!vis[nr][nc][ne][nmask]){
                    vis[nr][nc][ne][nmask]=true;
                    q.push({nr,nc,ne,nmask,moves+1});
                }
            }
        }
        return -1;
    }
};