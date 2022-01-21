/*https://leetcode.com/problems/integer-break/*/
class Solution {
public:
    int integerBreak(int n) {
       vector<int> dp (n+1, -1) ;
        dp[2]=dp[1]=1;
        return integerBreakUtil(n,dp);
        
    }
    int integerBreakUtil(int n, vector<int> & dp){
        if(dp[n]!=-1){return dp[n];}
        int to = ceil(n/2.0)+1;
        for(int i=1; i< to ; i++){
            int second = integerBreakUtil(n-i, dp);
            int first = integerBreakUtil(i, dp);
            if(second<n-i){second =n-i;}
            if(first<i){first =i;}
            int product =  first *second ;
            dp[n]= max(dp[n] , product);
        }
        return dp[n];
        
    }
};
