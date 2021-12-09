/*https://leetcode.com/problems/maximum-xor-for-each-query/*/
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxNum = (int)pow(2,maximumBit)-1;
        vector<int> ans(nums.size());
        int xorRes=0;
        for(int i=0; i< nums.size(); i++){
            xorRes^=nums[i];
            ans[i]= bitDiff(xorRes, maxNum, maximumBit);
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
        
    }
    int bitDiff(int num1, int num2, int length){
        int result=0;
        for(int i=0; i<length; i++){
            if( ((num1>>i)&1) ^ ((num2>>i)&1)) {
                result =  result | 1<<i    ;
            }
        }
        return result;
    }
};
