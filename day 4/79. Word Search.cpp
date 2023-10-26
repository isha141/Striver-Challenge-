class Solution { 
    int n,m;
    bool solve(int i,int j,string &word,int k,vector<vector<char>>&board){
          if(k>=word.size())
                return 1;
         if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='.' || board[i][j]!=word[k])
              return 0;
        char ch=board[i][j];
        board[i][j]='.';
        bool l=solve(i+1,j,word,k+1,board);
        bool r=solve(i-1,j,word,k+1,board);
        bool u=solve(i,j-1,word,k+1,board);
        bool d=solve(i,j+1,word,k+1,board);
        board[i][j]=ch;
        return (l | r | u| d);
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
           n=board.size();
           m=board[0].size();
          for(int i=0;i<n;++i){
              for(int j=0;j<m;++j){
                  if(board[i][j]==word[0]){
                      if(solve(i,j,word,0,board))
                            return 1;
                  }
              }
          }
        return 0;
    }
};
