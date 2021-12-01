/*https://leetcode.com/problems/count-sorted-vowel-strings/*/
class Solution {
public:
    unordered_set<string> allStr;
    vector<char> vowels={'a','e','i','o','u'};
    int count=0;
    int countVowelStrings(int n) {
        genStr(n);
        return count;
    }
    void genStr (int n, string s="", int start=0){
        if(n==0){count++;return;}
        for(int i=start; i<vowels.size(); i++){
            //s+=vowels[i];
            genStr(n-1,s,i);
           // s.pop_back();
        }
    }
};
