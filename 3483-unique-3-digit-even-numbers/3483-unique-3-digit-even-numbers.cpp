class Solution {
public:
    int totalNumbers(vector<int>& d){
        unordered_set<int> s;
        for(int i=0;i<d.size();i++){
            if(d[i]==0) continue;
            for(int j=0;j<d.size();j++){
                if(i==j) continue;
                for(int k=0;k<d.size();k++){
                    if(i==k || j==k) continue;
                    if(d[k]%2 != 0) continue;
                    s.insert((d[i]*100)+(d[j]*10)+d[k]);
                }
            }
        }
        return s.size();
    }
};