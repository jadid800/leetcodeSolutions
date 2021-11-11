/*https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBSTUtil(vector<int>& nums , int start, int end){
        if(end<start ){return nullptr;}
        
        int mid= (start+end)>>1;
        return new TreeNode(nums[mid],sortedArrayToBSTUtil(nums, start,mid-1) , sortedArrayToBSTUtil(nums, mid+1,end) ); 
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTUtil(nums, 0, nums.size()-1);
    }
   
};
