/*https://leetcode.com/problems/merge-intervals/*/
bool comparator(vector<int> & v1,vector<int> & v2){
        return v1[0]<v2[0];
    }
class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), comparator );
        vector<vector<int>> ans;
        int start=intervals[0][0], i=0,end= intervals[0][1];
        while(true){
            if(i==intervals.size()-1){
                end= max(end,intervals[i][1] );
                ans.push_back({start,end});
                break;
            }
            end= max(end,intervals[i][1] );
            if(!(end>=intervals[i+1][0])){
                ans.push_back({start, end});
                end= intervals[i+1][1];
                start= intervals[i+1][0];
            }
            i++;
        }
        return ans;
    }
};
