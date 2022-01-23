/*https://leetcode.com/problems/sequential-digits/*/
class Solution {
public:
    unordered_set <int> ans;
    vector<int> sequentialDigits(int low, int high) {
         for(int i=0; i<10; i++){
             util2(i,low, high,i+1);
         }
        vector<int> ans1;
        for(int  i: ans){
            ans1.push_back(i);
        }
        sort(ans1.begin(), ans1.end());
        return ans1;
        
    }
    void util2(int digit , int low, int high, int number){
        if(digit>=low && digit<=high){
            ans.insert(digit);
        }
        if(digit>high|| number>9){return;}
        
        util2(digit*10+number, low, high, number+1);
        
        
    }
  
};
