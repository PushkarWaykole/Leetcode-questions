#define vi vector<int>

class Solution {
    
    
private:
    bool dfs(int node,vector<int> adj[],vi &vis,vi &pathvis,vi &check){
        
        vis[node]=pathvis[node]=1;
        check[node]=0;
        for(auto it:adj[node]){
            
            // if the adjacent node make a cycle then it is not a safe node
            if(!vis[it] and dfs(it,adj,vis,pathvis,check)){
                check[it]=0;
                return true;
            }
            
            // if the adjacent node is present in the path containing a cycle then it cannot be a safe node
            else if(pathvis[it]){
                check[it]=0;
                return true;
            }
        }
        check[node]=1;
        pathvis[node]=0;
        return false;
        
    }   
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }
        vi vis(n,0);
        vi pathvis(n,0);
        vi check(n,0);
        vi safe_nodes;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,pathvis,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]==1){
                safe_nodes.push_back(i);
            }
        }
        return safe_nodes;
        
    }
};