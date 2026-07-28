class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n=apples.size();
        int c=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int day=0;
        while(day<n || !pq.empty()){
            if(day<n && apples[day]>0){
                pq.push({day+days[day],apples[day]});
            }
            while(!pq.empty() && pq.top().first<=day) {
                pq.pop();
            }
            if(!pq.empty()){
                auto p=pq.top();
                pq.pop();
                p.second--;
                c++;
                if(p.second>0){
                    pq.push(p);
                }
            }
            day++;
        }
        return  c;
    }
};