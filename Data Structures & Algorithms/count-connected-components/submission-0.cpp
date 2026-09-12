class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);

        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int components = 0;
        for(int node = 0;node < n;node++){
            if(!visited[node]){
                dfs(adj,visited,node);
                components++;
            }
        }
        return components;
    }
    void dfs(vector<vector<int>>& adj,vector<bool>& visited,int node){
        visited[node] = true;
        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                dfs(adj,visited,neighbor);
            }
        }
    }
};
