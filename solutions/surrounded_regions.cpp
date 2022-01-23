/*https://leetcode.com/problems/surrounded-regions/*/
class Solution {
public:
    vector<vector<int>> directions= { {1,0}, {-1,0}, {0,1}, {0,-1}};
    void solve(vector<vector<char>>& board) {
        for(int i=0 ; i<board[0].size(); i++){
            if(board[0][i]=='O'){
                bfs(board,0,i);
            }
            if(board[board.size()-1][i]=='O'){
                bfs(board,board.size()-1,i );
            }
        }
        for(int i=0 ; i< board.size();i++){
            if(board[i][0]=='O'){
                bfs(board,i,0);
            }
            if(board[i][board[0].size()-1]=='O'){
                bfs(board,i,board[0].size()-1);
            }
        }
        for(int i=0 ; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]=='1'){board[i][j]='O';continue;}
                board[i][j]='X';
            }
        }
        
        
    }
    void bfs(vector<vector<char>>& board, int row, int col){
        board[row][col]='1';
        for(int i=0 ; i< directions.size() ; i++){
            int newRow= row+directions[i][0];
            int newCol = col + directions[i][1];
            bool validDirection = isValid(board, newRow, newCol);
            if(validDirection && board[newRow][newCol]=='O' ){
                bfs(board, newRow, newCol);
            }
        }
        
    }
    bool isValid(vector<vector<char>>& board , int row, int col){
        return row>-1 && row<board.size() && col>-1 && col<board[0].size();
    }
};
