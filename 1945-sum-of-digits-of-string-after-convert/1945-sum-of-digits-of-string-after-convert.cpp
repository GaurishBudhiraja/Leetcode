class Solution {
public:
    int getLucky(string s, int k) {
        int p=0;
        for (char c:s){
            int val = c - 'a' + 1;
            while(val > 0) {
                p+=val%10;
                val/=10;
            }
        }
        for (int i=0;i<k-1;i++){
            int sum = 0;
            while(p>0) {
                sum+=p%10;
                p/=10;
            }
            p = sum;
        }
        
        return p;
    }
};