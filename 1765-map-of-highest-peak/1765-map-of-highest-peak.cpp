class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& w){
        int m=w.size(),n=w[0].size();
        vector<vector<int>> h(m, vector<int>(n,m+n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(w[i][j] == 1){
                    h[i][j] = 0;
                }else{
                    if(i>0){ 
                        h[i][j] = min(h[i][j],h[i-1][j]+1);
                    } 
                    if(j>0){
                        h[i][j] = min(h[i][j],h[i][j-1]+1);
                    }
                }
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i<m-1){
                    h[i][j] = min(h[i][j],h[i+1][j]+1);
                }
                if(j<n-1){ 
                    h[i][j] = min(h[i][j],h[i][j+1]+1);
                }
            }
        }
        return h;
    }
};