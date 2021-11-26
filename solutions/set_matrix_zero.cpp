/*https://leetcode.com/problems/set-matrix-zeroes/*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row0;
        unordered_set<int> col0;
        for(int i=0 ; i< matrix.size(); i++){
            for(int j=0 ; j<matrix[i].size(); j++){
                if(matrix[i][j]==0){
                    row0.insert(i)                   ;
                    col0.insert(j);
                }
            }
        }
        for(int i=0 ; i< matrix.size(); i++){
            for(int j=0 ; j<matrix[i].size(); j++){
                if(row0.find(i)!= row0.end() || col0.find(j)!= col0.end()){
                 matrix[i][j]=0;
                }
            }
        }    
        }
        
    
};
