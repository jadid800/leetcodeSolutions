/*https://leetcode.com/problems/search-a-2d-matrix/*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ansRow= findRow(matrix, target);
        if(ansRow==-1){return false;}
        int lowerB = lower_bound(matrix[ansRow].begin(),matrix[ansRow].end(),target ) -matrix[ansRow].begin();
        return matrix[ansRow][lowerB]==target;
        
        
    }
    int findRow(vector<vector<int>>& matrix, int target){
        for(int i=0; i<matrix.size(); i++){
            if(target<=matrix[i][matrix[i].size()-1]){
                return i;
            }
        }
        return -1;
    }
};
