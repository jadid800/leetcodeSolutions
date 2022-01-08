/*https://leetcode.com/problems/minimum-falling-path-sum/*/
class Solution {
public:
    vector<vector<int>> moves = {{1,-1}, {1,0}, {1,1}};
    int minFallingPathSum(vector<vector<int>>& matrix) {
        if(matrix.size()==1){
            return  matrix[0][0];
        }
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-200));
        int ans=INT_MAX;
        for(int i=0; i<dp.size(); i++){
            fillDp(matrix,dp,i);
            ans=min(ans,dp[0][i]);
        }
        return ans;
        
        
    }
    void fillDp(vector<vector<int>> & matrix, vector<vector<int>>& dp, int index,int row=0){
        if(row==dp.size())return;
        if(dp[row][index]!=-200){return;}
        int minimumPath=INT_MAX;
        for(int i=0 ; i<moves.size(); i++){
            int x= row+moves[i][0];
            int y= index+moves[i][1];
            if(x==dp.size()-1){
                if(y>-1 && y<dp[0].size()){
                    dp[x][y]=matrix[x][y];
                    minimumPath = min(minimumPath, dp[x][y]);    
                }
            }
            else if(y>-1 && y<dp[0].size() ){
                fillDp(matrix,dp,y,x);
                minimumPath = min(minimumPath, dp[x][y]);
            }
        }
        dp[row][index]= matrix[row][index]+minimumPath;
        
        
    }
};
