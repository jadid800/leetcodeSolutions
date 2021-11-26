/*https://leetcode.com/problems/string-to-integer-atoi/*/
class Solution {
public:
    int myAtoi(string s) {
        int spacelessIndex=  removeSign(s);
       int sign= getSign(s, spacelessIndex); 
        long long int number =0;
        int iter =spacelessIndex;//= (sign==-1)? spacelessIndex+1: spacelessIndex;
        if(s[iter]=='+'|| s[iter]=='-'){iter++;}
        
        for(iter= iter;iter<s.size(); iter++ ){
            if(s[iter]>='0' && s[iter]<='9'){
             number*=10;
             number+=s[iter]-'0';
        if(number*sign<INT_MIN){return INT_MIN;}
        if(number*sign>INT_MAX){return INT_MAX;}
            }
            else{break;}
        }
        number*= sign;
        return number;
    }
   int removeSign(string s){
        int i=0;
        while(s[i]==' '){i++;}
        return i;
    }
    int getSign(string s, int index){
        return s[index]=='-'? -1:1;
    }
};
