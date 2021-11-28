/*https://leetcode.com/problems/all-paths-from-source-to-target/*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path={0};

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        allPathsSourceTargetUtil(graph);

        return ans;
    }
   void allPathsSourceTargetUtil(vector<vector<int>>& graph , int node=0){
        if(node==graph.size()-1){
            ans.push_back(path);          
            return ;
        }
        for(int i: graph[node]){
            path.push_back(i);
            allPathsSourceTargetUtil(graph, i);
            path.pop_back();
        }
        return ;

    }
};
