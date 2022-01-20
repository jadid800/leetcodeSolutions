/*https://leetcode.com/problems/koko-eating-bananas/*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int hi= * max_element(piles.begin(), piles.end());
        int lo= 1;
        while(lo<=hi){
            int mid = lo+ (hi-lo)/2;
            int time = timeToEat(piles, mid);
            if(time<=h){
                hi=mid-1;
            }
            else{lo=mid+1;}
            
        }
        return lo;
        
    }
    int timeToEat(vector<int> & piles , int & rate){
        int time=0;
        for(int & i : piles){
            time+= ceil(1.0* i/rate);
        }
        return time;
    }
};
