/*https://leetcode.com/problems/decode-string/*/
class Solution {
public:
    string decodeString(string s) {
        stack<string> stacK;
        for(int i=0; i<s.size();i++){
            string sc;
            sc+=s[i];
            if(stacK.size()==0 || s[i]!=']'){
                stacK.push(sc);
                continue;
            }
            string repeatStr="";
            while(stacK.top()!="["){
                repeatStr=stacK.top()+ repeatStr;
                stacK.pop();
            }
            stacK.pop();
            stacK.push(repeatStrFunc(getNo(stacK),repeatStr));
            
        }
        string actualStr= "";
        while(stacK.size()!=0){
            actualStr = stacK.top()+actualStr;
            stacK.pop();
        }
        return actualStr;
        
    }
    string repeatStrFunc(int number, string repeats){
        string s;
        for(int i=0; i<number; i++){
            s+=repeats;
        }
        return s;
        
    }
    int getNo(stack<string> & stacK){
        string noStr;
        while(stacK.size()!=0 && isNumber(stacK.top())){
            noStr=stacK.top()+noStr;
            stacK.pop();
          
        }
       
        return stoi(noStr);
        
    }
    bool isNumber(const string& str){
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}
    
};
