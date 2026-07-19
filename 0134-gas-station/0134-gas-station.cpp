class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int tg=0,tc=0,cg=0,sp=0;
        for(int i=0;i<n;i++){
            tg+=gas[i];
            tc+=cost[i];
            cg+=gas[i]-cost[i];
            if(cg<0){
                sp=i+1;
                cg=0;
            }
        }
        return(tg<tc)?-1:sp;     
    }
};