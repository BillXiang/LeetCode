/**
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to
its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
**/
#include <vector>
#include <stdbool.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int numOfStations = gas.size();
        int dif[numOfStations];
        for(int i=0; i<numOfStations; i++){
            dif[i] = gas[i] - cost[i];
        }
        int sum = 0;
        bool can = true;
        for(int i=0; i<numOfStations; i++){
            if(dif[i]<0){
                continue;
            }
            sum = 0;
            can = true;
            int j = i;
            for(; j<numOfStations+i; j++){
                sum += dif[j%numOfStations];
                if(sum<0){
                    i = j;
                    can = false;
                    break;
                }
            }
            if(can){
                return i;
            }
        }
        return -1;
    }
};

void canCompleteCircuitMain(void){
    int gas[] = {2, 4};
    int cost[] = {3, 4};
    vector<int> gasVector(gas, gas+2);
    vector<int> costVector(cost, cost+2);
    Solution().canCompleteCircuit(gasVector, costVector);
}
