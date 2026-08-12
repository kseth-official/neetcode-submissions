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

        // if only 1 gas station, then we can succeed if there's more gas than the cost
        // of leaving the station and coming back
        if (gas.size() == 1) {
            if (gas[0] >= cost[0])
                return 0;
            else
                return -1;
        }

        // // lowest available gas = 0, max gas cost = 1000, max diff = 0-1000 = -1000
        // // so we set max as the first number below our worst possible scenario
        // int maxD = -1001;
        // //unordered_set<int> startIndices = 0;
        // int startIndex = 0;
        // vector<int> differences;
        // for (int i=0;i<gas.size();i++) {
        //     if (gas[i]-cost[i] > maxD) {
        //         maxD = gas[i]-cost[i];
        //         startIndex = i;
        //     }
        // }

        // Running the simulation...
        for (int startIndex = 0; startIndex < gas.size(); startIndex++) {
            if (runSimulation(startIndex, gas, cost) > -1)
                return startIndex;
        }
        return -1;
    }

    int runSimulation(const int startIndex, const vector<int>& gas, const vector<int>& cost) {
        int i = startIndex;
        int currentFuel = 0;
        int count = 0;
        while (count < gas.size()) {
            i = i % gas.size(); // loop in a circular fashion

            currentFuel += gas[i]-cost[i];

            if (currentFuel < 0) {
                return -1;
            }
            
            count++;
            i++;
        }

        return startIndex;
    }
};
