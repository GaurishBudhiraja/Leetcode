class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        if(p.empty()) return 0;
        int c=1;
        sort(p.begin(),p.end());
        int prev = p[0][1];
        for(int i=1;i<p.size();i++){
            if(p[i][0]<=prev){
                prev = min(prev,p[i][1]);
            }
            else{
                c++;
                prev = p[i][1];
            }
        }
        return c;
    }
};