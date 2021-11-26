/*https://leetcode.com/problems/valid-sudoku/*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int size=9;
        
        unordered_set <string> dpSet ;
        for(int i=0; i<size; i++){
            for(int j=0 ; j<size ; j++){
                if(board[i][j]!='.' ){
                
                string rowFound= to_string(board[i][j]) +"at row "+to_string(i);
                string colFound = to_string(board[i][j]) +"at col "+to_string(j);
                string boxFound = to_string(board[i][j]) +"at box "+to_string(i/3) +" " + to_string(j/3) ;
                int prevSize= dpSet.size();
                dpSet.insert(rowFound);
                dpSet.insert(colFound);
                dpSet.insert(boxFound);
                if(dpSet.size()!= prevSize+3){return false;}
                }
                

                
            }
        }
        return true;
        
    }
