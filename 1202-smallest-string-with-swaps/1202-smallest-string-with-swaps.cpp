class Solution {
    struct subset {
        int parent;
        int rank;
    };
public:
    
    int find(struct subset subsets[], int i){
            
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets, subsets[i].parent);

        return subsets[i].parent;
    }

    
    void Union(struct subset subsets[], int xroot, int yroot){

        
        if (subsets[xroot].rank < subsets[yroot].rank)
            subsets[xroot].parent = yroot;
        else if (subsets[xroot].rank > subsets[yroot].rank)
            subsets[yroot].parent = xroot;
        else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int s_len = s.length();
        int n = pairs.size();
        string ans;

        struct subset* subsets = (struct subset*)malloc(s_len * sizeof(struct subset));
        for (int v = 0; v < s_len; v++) {
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }
        
        for (int e = 0; e < n; ++e) {
            
            int x = find(subsets, pairs[e][0]);
            int y = find(subsets, pairs[e][1]);

            if (x !=y) Union(subsets, x, y);
        }
        
        vector<pair<string, int>> arr(s_len);
        
        for(int i = 0; i < s_len ; i++){
            arr[find(subsets, i)].first += s[i];
            arr[find(subsets, i)].second = 0;
        }
        
        for(int i = 0; i < s_len ; i++){
            sort(arr[i].first.begin(), arr[i].first.end());
        }
        
        for(int i = 0; i < s_len ; i++){
            ans += arr[subsets[i].parent].first[arr[subsets[i].parent].second];
            arr[subsets[i].parent].second++;
        }
        
        return ans;
        
    }
};