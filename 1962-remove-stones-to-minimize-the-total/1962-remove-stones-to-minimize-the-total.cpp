class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int c=0;
        priority_queue<int>pq;
        for(int n:piles){
            pq.push(n);
        }
        while(k--){
            int x=pq.top()-floor(pq.top()/2);
            pq.pop();
            pq.push(x);
        }
        while(!pq.empty()){
            c+= pq.top();
            pq.pop();
        }
        return c;
    }
};