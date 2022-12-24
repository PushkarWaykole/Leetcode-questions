//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:

    bool bipartite(int node,vector<int> adj[],vector<int> &colors){
        
        
        for(auto it:adj[node]){
            if(colors[it]==-1){
                colors[it]=1-colors[node];
               if(!bipartite(it,adj,colors)){
                   return false;
               }
            }
            else if(colors[it]==colors[node]){
                return false;
            }
        }
        
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> colors(V,-1);
	    
	    for(int i=0;i<V;i++){
	        if(colors[i]==-1){
	            colors[i]=1;
	            if(!bipartite(i,adj,colors)){
	                return false;
	            }
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends