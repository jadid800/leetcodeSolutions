/*https://leetcode.com/problems/number-of-islands/*/
class Solution {
public:
    vector<vector<int>> directions= {{0,1},{0,-1}, {1,0}, {-1,0}};
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m = grid[0].size(), count=0; 
        for(int i=0 ; i< n ; i++){
            for(int j=0 ; j<m; j++){
                if(grid[i][j]=='1'){dfs(grid,i,j);count++;}
            }
        }
        return count;
        
    }
    void dfs(vector<vector<char>>& grid, int row, int col){
        int n=grid.size(), m = grid[0].size(); 
        if(row<0 || row>=n || col<0||col>=m||grid[row][col]!='1'){return;}
        grid[row][col]='2';
        for(auto & i : directions){
            dfs(grid, row+i[0], col+i[1]);
        }
        
    }
};
