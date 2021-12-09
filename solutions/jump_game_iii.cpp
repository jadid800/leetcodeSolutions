/*https://leetcode.com/problems/jump-game-iii/*/
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return canReachUtil(arr, visited, start);
        
    }
    bool canReachUtil(vector<int>& arr , vector<bool>& visited, int index){
        if(index>=arr.size()){
            return false;
        }
        if(visited[index]){return false;}
        if(arr[index]==0){return true;}
        visited[index]=true;
        return canReachUtil(arr, visited, index+arr[index])||canReachUtil(arr, visited, index-arr[index]);
    }
};
