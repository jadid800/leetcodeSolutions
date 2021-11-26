/*https://leetcode.com/problems/search-insert-position/*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target<nums[0])return 0;
        int index, low= 0, high= nums.size()-1;
        while(low<=high){
            index= (low+high)>>1;
            if(nums[index]==target){return index;}
            if(nums[index]<target){low= index+1;}
            else{high=index-1;}
        }
        
        return low ;
    }
};
