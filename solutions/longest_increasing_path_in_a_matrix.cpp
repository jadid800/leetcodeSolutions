/*https://leetcode.com/problems/longest-increasing-path-in-a-matrix/*/
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int ans=0;
        for(int i=0; i< matrix.size(); i++){
            for(int j=0; j<matrix[0].size();j++){
                int dfsans= dfs(i,j,dp,matrix);
                ans= max(ans, dfsans);
            }
        }
        return ans;
        
    }
    int dfs(int row, int col, vector<vector<int>>& dp ,vector<vector<int>> &matrix ,int taken=0){
        if(isInvalid(row , col, dp)) return 0;
        if(dp[row][col]!=-1){return dp[row][col];}
        int ans1=0 , ans2=0, ans3=0, ans4=0;
        if(!isInvalid(row+1, col, dp)){
            if(matrix[row][col]>matrix[row+1][col])
            {ans1 = dfs(row+1 , col, dp, matrix, taken+1);}
        }
        
        if(!isInvalid(row-1, col, dp)){
            if(matrix[row][col]>matrix[row-1][col])
            {ans2 = dfs(row-1 , col, dp, matrix, taken+1);}
        }
        if(!isInvalid(row, col+1, dp)){
            if(matrix[row][col]>matrix[row][col+1])
            {ans3 = dfs(row , col+1, dp, matrix, taken+1);}
        }
        if(!isInvalid(row, col-1, dp)){
            if(matrix[row][col]>matrix[row][col-1])
            {ans4 = dfs(row , col-1, dp, matrix, taken+1);}
        }
        dp[row][col]= 1+getMax({ ans1, ans2 ,ans3, ans4}) ; 
        return dp[row][col];
        
        
    }
    int getMax(vector<int> a){
        int ans=a[0];
        for(int i=1; i<a.size(); i++){
            ans= max(ans,a[i]);
        }
        return ans;
    }
    bool isInvalid(int row, int col,vector<vector<int>>& dp){
        return (row<0|| row>=dp.size() || col<0 || col>=dp[0].size());
    }
};
