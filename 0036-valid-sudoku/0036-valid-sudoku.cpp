class Solution {
public:
    bool isSudokuValid(vector<vector<char>>& board,int row,int col,char ch)
    {
        // check for row element..
        for(int j=0;j<9;j++){
            if(board[row][j]==ch)
                return false;
        }
        
        // check for column element..
        for(int i=0;i<9;i++){
            if(board[i][col]==ch)
                return false;
        }
        
        // check for submatrix element..
        int subRow=row/3;
        int subCol=col/3;
        
        int newRow=subRow*3;
        int newCol=subCol*3;
        
        for(int i=newRow;i<newRow+3;i++)
        {
            for(int j=newCol;j<newCol+3;j++)
            {
                if(board[i][j]==ch)
                    return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.')
                {
                    char ch=board[i][j];
                    board[i][j]='.';
                    bool res=isSudokuValid(board,i,j,ch);
                    board[i][j]=ch;
                    if(!res) return false;
                }
            }
        }
        return true;
    }
};