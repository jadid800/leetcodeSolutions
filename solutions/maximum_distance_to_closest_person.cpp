/*https://leetcode.com/problems/maximize-distance-to-closest-person/*/
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        priority_queue<int, vector<int>, greater<int> > filledSeat;
        int n= seats.size();
        filledSeat.push(n);
        int prev= -1, next, distFromBack, distFromFront, maximumDist=0;
        for(int i=0 ; i< n; i++){
            if(seats[i]){filledSeat.push(i);}
        }
        for(int i=0 ; i<n; i++){
            next= filledSeat.top();
            distFromBack= i-prev;
            distFromFront = next - i;
            int dist = min(distFromBack , distFromFront);
            maximumDist = max (maximumDist , dist);
            if(next==n){maximumDist = max (maximumDist , distFromBack);}
            if(prev==-1){maximumDist = max (maximumDist , distFromFront);}
            if(next==i){filledSeat.pop(); prev= next;}
        }
        return maximumDist;
        
    }
};
