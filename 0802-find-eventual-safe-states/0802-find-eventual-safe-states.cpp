class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       int n = graph.size();
       vector<vector<int>>adj(n);
       vector<int>outdeg(n,0);
       queue<int>q;

       for(int i = 0 ; i < n ; i++){
         for(int x : graph[i]){
            adj[x].push_back(i);
         }
         outdeg[i] = graph[i].size();
         if(outdeg[i] == 0){
            q.push(i);
         }
       }

       vector<bool>safe(n,false);
       vector<int>ans;

       while(!q.empty()){
        int u = q.front();
        q.pop();
        safe[u] = true;
        for(int v : adj[u]){
            if(--outdeg[v] == 0){
                q.push(v);
            }
        }
       }
       for(int i = 0 ; i < n ; i++){
          if(safe[i] == true){
            ans.push_back(i);
          }
       }

       return ans;
    }
};