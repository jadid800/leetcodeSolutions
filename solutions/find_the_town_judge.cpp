/*https://leetcode.com/problems/find-the-town-judge/*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustedPeople(n+1,0);
        vector<int> trusts(n+1,0);
        int countJudge=0,  judge=-1;
        for(int i=0; i<trust.size();i++){
            trustedPeople[trust[i][1]]++;
            trusts[trust[i][0]]++;
        }
        for(int i=1; i<=n;i++){
            if(trustedPeople[i]==n-1 && trusts[i]==0){
                countJudge++;
                judge=i;
            }
        }
        return countJudge==1?judge:-1;
        
    }
};
