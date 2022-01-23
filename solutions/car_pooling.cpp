/*https://leetcode.com/problems/car-pooling/*/
struct startFirst{
    bool operator()(vector<int> & trip1, vector<int> & trip2 ){
        return !(trip1[1]<trip2[1]);
        
    }
};
struct endFirst{
    bool operator()(vector<int> & trip1, vector<int> & trip2 ){
        return !(trip1[2]<trip2[2]);
        
    }
};
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue < vector<int> , vector<vector<int>> , startFirst> startQ;
        priority_queue < vector<int> , vector<vector<int>> , endFirst> endQ;
        for( auto & i : trips){
            startQ.push(i);
        }
        while(!startQ.empty()){
                while(!endQ.empty() && endQ.top()[2]<=startQ.top()[1]){
                    capacity+=endQ.top()[0];
                    endQ.pop();
                }
            
            if(capacity<startQ.top()[0]){
                return false;
            }
            capacity-=startQ.top()[0];
            endQ.push(startQ.top());
            startQ.pop();
            
        }
        return true;
        
    }
};
