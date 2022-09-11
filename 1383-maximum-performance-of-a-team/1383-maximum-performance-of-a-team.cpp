class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int MOD = 1e9 + 7;
        vector<pair<int, int>> candidates(n);
      
        for (int i = 0; i < n; i++) candidates[i] = { efficiency[i], speed[i] };
        
        sort(candidates.rbegin(), candidates.rend());
        
        long speedSum = 0, ans = 0;
       
        priority_queue <int, vector<int>, greater<int>> pq;
        // iterate each pair
        for (auto& [e, s] : candidates) {
            // put the speed to priority queue
            pq.push(s);
            // add to speedSum
            speedSum += s;
            
            if (pq.size() > k) {
               
                speedSum -= pq.top();
                pq.pop();
            }
          
            ans = max(ans, speedSum * e);
        }
        return ans % MOD;
    }
};