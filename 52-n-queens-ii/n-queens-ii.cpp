class Solution {
    private:
    int ans=0;
bool isSafe(int row,int col,vector<vector<string>>& board,int n){
    int x=row;
    int y=col;

    while(y>=0){
        if(board[x][y]=="Q")
        return false;

        y--;
    }

    x=row;
    y=col;
    while(x>=0 && y>=0){
        if(board[x][y]=="Q")
        return false;

        x--;
        y--;
    }

    x=row;
    y=col;
    while(x<n && y>=0){
        if(board[x][y]=="Q")
        return false;

        x++;
        y--;
    }

    return true;
}
    void solve(int col, vector<vector<string>>& board, int n){
    if(col==n){
        ans++;
        return;
    }

    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]="Q";
            solve(col+1,board,n);
            board[row][col]=".";
        }
    }
}
public:
    int totalNQueens(int n) {
    vector<vector<string>> board(n,vector<string> (n,"."));
    solve(0,board,n);
    return ans;
    }
};