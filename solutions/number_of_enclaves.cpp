/*https://leetcode.com/problems/number-of-enclaves/*/
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row= grid.size(), col= grid[0].size();
        vector<vector<int>> visited1(row,vector<int>(col,0));
        vector<vector<int>> visited2(row,vector<int>(col,0));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]){
                    if(isBorder(row, col , i,j)){
                        visited1[i][j]=1;
                        visited2[i][j]=1;
                    }
                    else{visited1[i][j]=-1;}
                }
            }
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(visited2[i][j]){
                    fillMove(visited1,i,j);
                }
            }
        }
        return countNotBorder(visited1);
    }
    void fillMove(vector<vector<int>>& grid, int i, int j){
        bool valid =isValid(grid.size() , grid[0].size() , i,j);
        
        if(!valid){return;}
        if(grid[i][j]==2){return;}
        if(grid[i][j]==0){return;}
        grid[i][j]=2;
        fillMove(grid, i-1,j);
        fillMove(grid, i+1,j);
        fillMove(grid, i,j-1);
        fillMove(grid, i,j+1);
        
    }
    int countNotBorder(vector<vector<int>>& visited){
        int count=0;
        for(auto i: visited){
         for(auto j : i){
            if(j==-1)count++;
         }
     }
        return count;
    }
    bool isBorder(int row, int col, int rowIndex, int colIndex){
        return rowIndex==0 || colIndex==0 || rowIndex==row-1|| colIndex==col-1;
    }
    bool isValid(int row, int col, int rowIndex, int colIndex){
        return rowIndex>=0&& colIndex>=0 && rowIndex<row && colIndex<col;
    }
};
