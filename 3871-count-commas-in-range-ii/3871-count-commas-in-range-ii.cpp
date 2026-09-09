class Solution {
public:
    long long countCommas(long long n) {
        long long c=0,s=1000;
        if(n<1000) return 0;
        while(s<=n){
            c+= n-s+1;
            s*=1000;
        }
        return c;
    }
};