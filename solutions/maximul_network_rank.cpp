/*https://leetcode.com/problems/maximal-network-rank/*/
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> graph(n);
        int rank=0;
        for(int i=0; i< roads.size();i++){
            graph[roads[i][0]].insert(roads[i][1]);
            graph[roads[i][1]].insert(roads[i][0]);
        }
        for(int i=0; i<n;i++){
            for(int j=i+1; j<n; j++){
                int ans= graph[i].size()+graph[j].size();
                if(graph[i].find(j)!=graph[i].end()){
                    ans-=1; 
                }
                rank= max(rank,ans);
                    
            }
        }
        return rank;
        
    }
};
