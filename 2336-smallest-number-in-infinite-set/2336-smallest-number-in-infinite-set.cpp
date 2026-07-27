class SmallestInfiniteSet {
public:
    int curr;
    priority_queue<int,vector<int>,greater<int>> pq;
    unordered_set<int> s;
    SmallestInfiniteSet() {
        curr=1;
    }
    int popSmallest() {
        if(!pq.empty()){
            int smallest=pq.top();
            pq.pop();
            s.erase(smallest);
            return smallest;
        }
        return curr++;
    }
    void addBack(int num) {
        if(num<curr && s.find(num) == s.end()){
            pq.push(num);
            s.insert(num);
        }
    }
};
