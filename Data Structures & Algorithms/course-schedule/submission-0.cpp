class Solution {
public:
    bool hasCycle(int node,vector<vector<int>>& adj,vector<int>& state){
        state[node] = 1;
        
        for(int neighbor : adj[node]){
            if(state[neighbor] == 1){
                return true;
            }
            else if(state[neighbor] == 0){
                if(hasCycle(neighbor,adj,state)){
                    return true;
                }
            }
        }
        state[node] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int>state(numCourses,0);

        for(auto& pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }
        for(int i = 0;i < numCourses;i++){
            if(state[i] == 0){
                if(hasCycle(i,adj,state)){
                    return false;
                }
            }
        }
        return true;
    }
};
