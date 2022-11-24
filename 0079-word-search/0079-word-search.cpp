class Solution {
public:
    
    bool dfs(vector<vector<char>> &board,string word,int i,int j
            ,int n,int m){
        
        if(word.size()==0){
            return true;
        }
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[0]){
            return false;
        }
        char c=board[i][j];
        board[i][j]='*';
        string s=word.substr(1);
        
        bool res= dfs(board,s,i-1,j,n,m) || dfs(board,s,i,j-1,n,m) ||dfs(board,s,i+1,j,n,m) || dfs(board,s,i,j+1,n,m);
        
        board[i][j]=c;
        return res;
        
    }
    
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board,word,i,j,n,m)){
                    return true;
                }
            }
        }
        return false;
    }
};