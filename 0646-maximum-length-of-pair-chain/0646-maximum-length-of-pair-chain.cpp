class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {
        int c=1;
        sort(p.begin(),p.end());
        int prev = p[0][1];
        for(int i=1;i<p.size();i++){
            if(prev < p[i][0]){
                c++;
                prev = p[i][1];
            }
            else{
                prev = min(prev,p[i][1]);
            }
        }
        return c;
    }
};