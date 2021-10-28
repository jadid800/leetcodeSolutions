/* https://leetcode.com/problems/subsets/*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int numbers= nums.size();
        int noOfSets= 1<<nums.size();
        vector<vector<int>> allsubsets;
        for(int i=0; i<noOfSets; i++){
            vector<int> set1;
            for(int j=0;j<numbers;j++){
                if(i>>j &1){
                    set1.push_back(nums[j]);
                }
            
            }
            allsubsets.push_back(set1);
        }
        return allsubsets;
        
    }
};
