class Solution {
    
    
private:
    void dfs(vector<vector<int>>& graph,vector<vector<int>>& paths,vector<int> &path,int node){
        path.push_back(node);
        if(node==graph.size()-1){
            paths.push_back(path);
        }
        else{
            for(auto it:graph[node]){
                dfs(graph,paths,path,it);
            }
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(graph,paths,path,0);
        return paths;
    }
};