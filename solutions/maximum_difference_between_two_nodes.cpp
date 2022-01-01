/*https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/*/
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
    int maxDiff= 0;
    int maxAncestorDiff(TreeNode* root) {
        smallDownDiff(root);//smallUpDiff(root);
        return maxDiff;
        
    }
    pair<int,int> smallDownDiff(TreeNode* root){
        if(root==nullptr){return make_pair(-1e6+1, 1e6+1);}
        pair<int,int> leftAns= smallDownDiff(root->left);
        pair<int,int> rightAns= smallDownDiff(root->right);
        int maxI = max(leftAns.first ,rightAns.first);
        int minI = min(leftAns.second ,rightAns.second);
        maxDiff = max(maxDiff,maxI-root->val);
        maxDiff = max(maxDiff , root->val - minI);
        return {make_pair(max(maxI,root->val) ,min(minI,root->val))};
    }

};
