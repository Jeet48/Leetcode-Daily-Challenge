class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(!pq.empty()) {
            int a = pq.top();
            pq.pop();
            int c;
            if(!pq.empty()){
                c=pq.top();
                pq.pop();
            }
            else {
                break;
            }
            pq.push(abs(a-c));
        }
        return pq.top();
    }
};