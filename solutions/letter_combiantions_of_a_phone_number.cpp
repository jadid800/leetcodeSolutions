/*https://leetcode.com/problems/letter-combinations-of-a-phone-number/*/
class Solution {
public:
        vector<char> getChar(int digit){
        if(digit==2){
            return {'a', 'b', 'c'};
        }
        if(digit==3){
            return {'d', 'e', 'f'};
        }
        if(digit==4){
            return {'g', 'h', 'i'};
        }if(digit==5){
            return {'j', 'k', 'l'};
        }if(digit==6){
            return {'m', 'n', 'o'};
        }if(digit==7){
            return {'p', 'q', 'r','s'};
        }if(digit==8){
            return {'t', 'u', 'v'};
        }
        if(digit==9){
            return {'w', 'x', 'y','z'};
        }
        return {};
    }
    vector<string> letterCombinations(string digits) {
        if(digits==""){return {};}
        vector<string> ans;
        letterCombinationsUtil(digits, ans);
        return ans;
        
        
    }

    void letterCombinationsUtil(string digits, vector<string> & allSets, int start=0 , string  digitStr=""){
        if(start== digits.size()){
         allSets.push_back(digitStr)   ;
            return;
        }
        
        int digitInt = digits[start]-'0';
        vector<char> iterate= getChar(digitInt);
        for(char i : iterate){
            digitStr+=i;
            letterCombinationsUtil(digits, allSets, start+1, digitStr);
            digitStr.pop_back();
        }
              
    }
};
