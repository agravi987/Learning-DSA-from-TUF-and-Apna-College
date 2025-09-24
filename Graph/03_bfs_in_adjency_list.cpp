class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int V = adj.size() ; 
        vector<int> visted(V , 0) ; 
        vector<int> ans ; 
        
        queue<int> q ; 
        
        q.push(0) ; 
        
        while(!q.empty()){
            int node =  q.front() ; q.pop() ;
            
            if(!visted[node]){
                visted[node] = 1 ; 
                ans.push_back(node) ; 
                
                for(auto it : adj[node]){
                    q.push(it) ; 
                }
            }
        }
        
        
        return ans ; 
    }
};