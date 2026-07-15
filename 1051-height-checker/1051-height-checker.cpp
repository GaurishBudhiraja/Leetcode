class Solution {
public:
    int heightChecker(vector<int>& h) {
        int c=0;
        vector<int> cp(h.begin(),h.end());
        sort(cp.begin(),cp.end());
        for(int i=0;i<h.size();i++){
            if(h[i] != cp[i]){
                c++;
            }
        }
        return c;
    }
};