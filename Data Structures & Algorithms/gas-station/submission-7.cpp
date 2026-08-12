class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*
            Solution: currI = startI (looped back around)
            Termination: cannot progress and currI != startI (unless just starting)

            A naive optimization we can make is to start at the gas station
            with the where the difference between gas and cost to next station
            is maximum.

            Counterexample?

            If not counterexample, then starting at that gas station, let's run
            our simulation. If at any point we cannot purchase enough gas to get to the
            next station, we return -1, unless we already came back to our starting station.
        */

        int gasSum = 0;
        int costSum = 0;
        for (int i=0;i<gas.size();i++) {
            gasSum+=gas[i];
            costSum+=cost[i];
        }
        if (gasSum < costSum)
            return -1;

        return runSimulation(0,gas,cost);
    }

    int runSimulation(int startIndex, const vector<int>& gas, const vector<int>& cost) {
        int i = startIndex;
        int currentFuel = 0;
        int count = 0;
        while (count < gas.size()) {
            i = i % gas.size(); // loop in a circular fashion

            currentFuel += gas[i]-cost[i];

            if (currentFuel < 0) {
                count = 0;
                currentFuel = 0;
                i++;
                startIndex=i;
                continue;
            }
            
            count++;
            i++;
        }

        return startIndex;
    }
};
