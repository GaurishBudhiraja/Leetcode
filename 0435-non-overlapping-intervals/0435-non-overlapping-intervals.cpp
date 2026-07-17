class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        int c=0;
        sort(in.begin(),in.end());
        int prevEnd = in[0][1];
        for(int i=1;i<in.size();i++){
            if(in[i][0]<prevEnd) {
                c++;
                prevEnd = min(prevEnd,in[i][1]);
            }
            else{
                prevEnd = in[i][1];
            }
        }
        return c;
    }
};

