/*https://leetcode.com/problems/binary-tree-level-order-traversal/*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> orderLevelResult;
        queue<vector<TreeNode*>> bfsQueue;
        if(!root){return orderLevelResult;}
        orderLevelResult.push_back({root->val});
        bfsQueue.push({root});
        while(!bfsQueue.empty()){
            vector<TreeNode*> travel = bfsQueue.front();
            bfsQueue.pop();
            vector<int> levelValues;
            vector<TreeNode*> levelNodes;
            for(auto i : travel){
                if(i->left){
                    levelNodes.push_back(i->left);
                    levelValues.push_back(i->left->val);
                }
                if(i->right){
                    levelNodes.push_back(i->right);
                    levelValues.push_back(i->right->val);
                }
            }
            if(levelValues.size()==0){break;}
            orderLevelResult.push_back(levelValues);
            bfsQueue.push(levelNodes);
        }
        return orderLevelResult;   
    }
};
