/*https://leetcode.com/problems/watering-plants-ii/*/
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int fillUp=0;
        int fillA=0, fillB=plants.size()-1, aWater= capacityA, bWater = capacityB;
        while(!(fillA>fillB)){
            if(fillA==fillB){
                if(aWater>=bWater){watering(fillUp, plants, fillA , aWater, capacityA); break;}
                watering(fillUp, plants, fillB, bWater,capacityB); break;
            }
            
            watering(fillUp, plants, fillA , aWater, capacityA);
            watering(fillUp, plants, fillB, bWater,capacityB);
            fillA++;fillB--;
        }
        return fillUp;
    
    }
    void watering(int & fillUp , vector<int> & plants, int &index, int & waterSize , int & capacity){
        if(waterSize< plants[index]){
            fillUp++;
            waterSize= capacity;
        }
        waterSize-=plants[index];
    }
};
