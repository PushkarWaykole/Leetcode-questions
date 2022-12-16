//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  
    void dfs(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &vis,
    vector<pair<int,int>> &vec,int row0,int col0){
        vis[row][col]=1;
        int n=grid.size(),m=grid[0].size();
        vec.push_back({row-row0,col-col0});
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int nr=row+dx[i],nc=col+dy[i];
            if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc]
            and grid[nr][nc]==1){
                dfs(nr,nc,grid,vis,vec,row0,col0);
            }
        }
    }
  
  
  
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,grid,vis,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends