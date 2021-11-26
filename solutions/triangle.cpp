/*https://leetcode.com/problems/triangle/*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        for(int i=0; i<triangle.size(); i++){
            for(int j=0; j< triangle[i].size(); j++){
                dp[i][j]=10e5;
            }
        }
        
        return minimumTotalUtil(triangle, dp);
    }
    int minimumTotalUtil(vector<vector<int>>& triangle, 
                        vector<vector<int>>& dp, 
                        int rowNo=0, int index=0,int sum=0){
        
        if(rowNo== triangle.size()){
            return 0;
        }
        if(dp[rowNo][index]!= 10e5){return dp[rowNo][index];}
        sum+=triangle[rowNo][index];
        int sameIndex= minimumTotalUtil(triangle,dp, rowNo+1,index,sum);
        int increasedIndex= minimumTotalUtil(triangle,dp, rowNo+1,index+1, sum);
        int optimal=min(sameIndex, increasedIndex)+triangle[rowNo][index];
        dp[rowNo][index]=optimal;
        
        return optimal;
        
    }
};
