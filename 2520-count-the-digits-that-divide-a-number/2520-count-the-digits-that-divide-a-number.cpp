class Solution {
public:
    int countDigits(int num) {
        int c=0;
        int tmp=num;
        while(num>0){
            int dig = num%10;
            if(tmp%dig == 0){
                c++;
            }
            num/=10;
        }
        return c;
    }
};