class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int station = 0;
        int totalGas = 0;
        int currTank = 0;
        for(int i=0; i<cost.size(); i++) {
            totalGas += (gas[i] - cost[i]);
            currTank += (gas[i] - cost[i]);
            
            if(currTank < 0) {
                station = i+1;
                currTank = 0;
            }
        }

        return totalGas >= 0 ? station : -1;
    }
};