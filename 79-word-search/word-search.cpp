class Solution {
    private:
    bool solve(int i,int j,int n,int m,vector<vector<char>>& board, string word,int k){
        if(k==word.size())
        return true;
        if(i<0|| i>=n|| j<0|| j>=m || board[i][j]!=word[k])
        return false;
        // board[i][j]='.';

        char temp=board[i][j];
        board[i][j]='.';

        bool found = solve(i+1,j,n,m,board,word,k+1)||solve(i-1,j,n,m,board,word,k+1)||
        solve(i,j+1,n,m,board,word,k+1)||solve(i,j-1,n,m,board,word,k+1);
        
        board[i][j]=temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        // int k=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(solve(i,j,n,m,board,word,0))
                    return true;
                }
            }
        }
        return false;
    }
};