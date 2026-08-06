class Solution {
public:
    int smallestNumber(int n, int t) {
        while(1){
            int prod=1;
            int temp=n;
            while(temp){
                prod *= temp%10;
                temp/=10; 
            }
            if(prod%t == 0){
                return n;
            }
            n++;
        }
    }
};