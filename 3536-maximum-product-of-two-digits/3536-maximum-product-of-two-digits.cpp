class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int,vector<int>,greater<int>>pq;
        while(n!=0){
            int d=n%10;
            pq.push(d);
            if(pq.size()>2){
                pq.pop();
            }
            n/=10;
        }
        int a=pq.top();
        pq.pop();
        return a*pq.top();
    }
};