class Solution {
public:
    
    
    bool checkComponentsForBipartiteness(vector<vector<int>>& graph, int src, vector<int>&marked_levels){
        queue<pair<int,int>> q; // stores the vertex and its corresponding level .
        q.push({src,0});
        while(q.size() > 0){
            pair<int,int> vertex = q.front();
            q.pop();
            
           
            if(marked_levels[vertex.first] != -1){
                if(marked_levels[vertex.first] != vertex.second){
                    return false;
                }
            }
            
          
            else{
                marked_levels[vertex.first] = vertex.second;
            }
            
            
            
            for(int v : graph[vertex.first]){
                if(marked_levels[v] == -1){
                    q.push({v,vertex.second+1});
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
       
        vector<int> marked_levels(graph.size(), -1);
        
       
        for(int i=0;i<graph.size();i++){
            if(marked_levels[i] == -1){
                bool bipartite = checkComponentsForBipartiteness(graph, i, marked_levels);
                if(bipartite == false){
                    return false;
                }
            }
        }
        return true;
    }
};
