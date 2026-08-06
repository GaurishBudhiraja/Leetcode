class Solution {
public:
    int smallestNumber(int n, int t) {
        int num=n;
        while(num >= n){
            int prod=1;
            int temp=num;
            while(temp != 0){
                int dig = temp%10;
                prod *= dig;
                temp/=10; 
            }
            if(prod%t == 0){
                return num;
            }
            num++;
        }
        return num;
    }
};