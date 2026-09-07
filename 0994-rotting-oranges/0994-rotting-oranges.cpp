class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),t=0,f=0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) f++;
            }
        }
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty() && f){
            int s=q.size();
            while(s--){
                auto [r,c]=q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    int x=r+dr[d],y=c+dc[d];
                    if(x>=0&&x<m&&y>=0&&y<n&&grid[x][y]==1){
                        grid[x][y]=2;
                        f--;
                        q.push({x,y});
                    }
                }
            }
            t++;
        }
        return f? -1:t;
    }
};