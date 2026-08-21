class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        for(int i=t.size()-2;i>=0;i--){
            for(int j=0;j<t[i].size();j++){
                int below = t[i+1][j];
                int belowRight = t[i+1][j+1];
                t[i][j]+=min(below,belowRight);
            }
        }
        return t[0][0];
    }
};