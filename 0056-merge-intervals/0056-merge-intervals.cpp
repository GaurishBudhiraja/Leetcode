class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        vector<vector<int>> res;
        res.push_back(in[0]);
        for(int i=1;i<in.size();i++){
            if(in[i][0]<=res.back()[1]){
                res.back()[1] = max(res.back()[1], in[i][1]);
            }
            else{
                res.push_back(in[i]);
            }
        }
        return res;
    }
};