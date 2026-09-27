class Solution {
    private:
    bool isSafe(vector<vector<char>>& board,int r,int col,char c){
        for(int i=0;i<9;i++){
            if(i!=r && board[i][col]==c)
            return false;

            if(i!=col && board[r][i]==c)
            return false;
            int l=3*(r/3) + i/3;
            int m=3*(col/3)+ i%3;
            if((l!=r || m!=col) && board[l][m]==c)
            return false;
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                if(board[i][j]!='.'){
                    if(!isSafe(board,i,j,board[i][j]))
                    return false;
                }
            }
        }
        return true;
    }
};