/*https://leetcode.com/contest/weekly-contest-269/problems/removing-minimum-and-maximum-from-array/*/
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minimumInd=0,maximumInd=0 ,moves= INT_MAX;
        for(int i=1 ; i < nums.size(); i++){
            if(nums[i]<nums[minimumInd]){minimumInd= i;}
            if(nums[i]>nums[maximumInd]){maximumInd= i;}
        }
        
        int moveMaxFromBack= nums.size()- maximumInd;
        int removeMinFromBack = nums.size()- minimumInd;
        int removeMaxFromFront = maximumInd+1;
        int removeMinFromFront = minimumInd+1;
        //option 1
        moves=min(moves,max(removeMinFromFront,removeMaxFromFront));
        //option 2;
        moves=min(moves, max(removeMinFromBack,moveMaxFromBack ));
        //option 3
        moves=min(moves, (removeMinFromBack+removeMaxFromFront));
        //option 4
        moves = min(moves , (removeMinFromFront+ moveMaxFromBack));
        return moves;
        
        
        
    }
};
