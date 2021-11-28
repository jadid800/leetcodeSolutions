/*https://leetcode.com/problems/power-of-four/*/
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1)return false;
        if(n==1) return true;
        if((int)log2(n)<2) return false;
        if((n&(n-1))==0){
            int count=0;
            while((n&1)==0){
                count++;
                n= n>>1;
            }
         
            if((count&1)==0)return true;
        }
        return false;
    }
};
