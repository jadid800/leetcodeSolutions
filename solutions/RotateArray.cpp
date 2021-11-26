/* https://leetcode.com/problems/rotate-array/*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int pivot = nums.size() - k;
        vector<int> numsRotated(nums.size());
        int index=0;
        for(int i= pivot; i < nums.size(); i++){
            numsRotated[index]= nums[i];
            index++;
        }
        for(int i=0 ; i<pivot; i++){
            numsRotated[index]= nums[i];
            index++;
            
        }
        nums=numsRotated;
    }
};
