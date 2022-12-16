//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    vector<int> dx{1,0,-1,0},dy{0,1,0,-1};
    
    void dfs(vector<vector<int>> &vis,vector<vector<char>> &mat,int i,int j,int n,int m){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nr=i+dx[k],nc=j+dy[k];
            if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc] and mat[nr][nc]=='O'){
                dfs(vis,mat,nr,nc,n,m);
            }
        }
        
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n+1,vector<int>(m+1,0));
        
        // first row 
        for(int i=0;i<m;i++){
            if(!vis[0][i] and mat[0][i]=='O'){
                dfs(vis,mat,0,i,n,m);
            }
        }
        
        // first column
        for(int i=0;i<n;i++){
            if(!vis[i][0] and mat[i][0]=='O'){
                dfs(vis,mat,i,0,n,m);
            }
        }
        
        // last row
        for(int i=0;i<m;i++){
            if(!vis[n-1][i] and mat[n-1][i]=='O'){
                dfs(vis,mat,n-1,i,n,m);
            }
        }
        
        
        // last col
        for(int i=0;i<n;i++){
            if(!vis[i][m-1] and mat[i][m-1]=='O'){
                dfs(vis,mat,i,m-1,n,m);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends