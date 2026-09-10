class Solution {
public:
    int nearestExit(vector<vector<char>>& maze,vector<int>& e) {
        int m=maze.size(),n=maze[0].size();
        queue<pair<int,int>>q;
        q.push({e[0],e[1]});
        maze[e[0]][e[1]] = '+';
        int st=0,dr[] = {-1, 1, 0, 0},dc[] = {0, 0, -1, 1};
        while(!q.empty()){
            int sz=q.size();
            st++;
            while(sz--){
                auto [r,c]=q.front();
                q.pop();
                for (int d=0;d<4;d++){
                    int nr=r+dr[d],nc=c+dc[d];
                    if(nr<0 || nr>=m || nc<0 || nc>=n) continue;
                    if(maze[nr][nc] == '+') continue;
                    if(nr == 0 || nr == m-1 || nc == 0 || nc == n-1) return st;
                    maze[nr][nc] = '+';
                    q.push({nr, nc});
                }
            }
        }
        return -1;
    }
};