/*https://leetcode.com/problems/gray-code/*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> sets;
        sets.push_back(0);
        generateGray(sets,n);
        return sets;
        
    }
    void generateGray(vector<int> &sets, int n, int prev=0){
        if(n==0){return;}
        generateGray(sets,  n-1, prev);
        prev= prev| (1<<(n-1));
        
        generateGray(sets,  n-1, prev);
        sets.push_back(prev);
    }
};
