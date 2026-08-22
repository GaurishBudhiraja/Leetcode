class Solution {
public:
    bool checkDivisibility(int n) {
        int tmp=n,sum=0,prod=1;
        while(tmp>0){
            int dig=tmp%10;
            sum+=dig;
            prod*=dig;
            tmp/=10;
        }
        if(n%(sum+prod)==0) return true;
        return false;
    }
};