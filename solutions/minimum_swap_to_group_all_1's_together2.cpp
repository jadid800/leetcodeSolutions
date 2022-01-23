/*https://leetcode.com/contest/weekly-contest-275/problems/minimum-swaps-to-group-all-1s-together-ii/*/
class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int oneCount = countNumber(nums, 1,nums.size());
        int minSwap=INT_MAX;
        int windowStart=0, windowEnd=oneCount-1;
        int end= windowEnd-1;
        int oneInWindow = countNumber(nums,1,windowEnd+1);
        minSwap=oneCount -oneInWindow;
        while(windowEnd!=end){
            if(nums[windowStart]==1){oneInWindow--;}
            windowEnd = (windowEnd+1)% nums.size();
            windowStart = (windowStart+1)% nums.size();
            if(nums[windowEnd]==1){oneInWindow++;}
            minSwap= min(minSwap, oneCount- oneInWindow);
            if(minSwap==0){return 0; }
        }
        return minSwap;   
    }
    int countNumber(vector<int> & nums , int digit, int end, int start=0){
        int count=0;
        for(int i=start; i<end; i++){
            if(nums[i]==digit){count++;}
        }
        return count;
    }
};
