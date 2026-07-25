class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long c=0;
        priority_queue<int>pq;
        for(int num:gifts){
            pq.push(num);
        }
        while(!pq.empty()){
            if(k>0){
                int x=floor(sqrt(pq.top()));
                pq.pop();
                k--;
                pq.push(x);
            }
            else{
                c+=pq.top();
                pq.pop();
            }
        }
        return c;
    }
};