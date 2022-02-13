class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        std::priority_queue<int> pq;
        int maxDistance=startFuel; 
        int stationsUsed=0;
        int stationsId=0;
        while (maxDistance<target ) {
            while (stationsId<stations.size() && stations[stationsId][0]<=maxDistance) {
                pq.push(stations[stationsId][1]);
                stationsId++;
            }
            if ( pq.size() == 0 ) break;
            int newStopFuel = pq.top();
            pq.pop();
            maxDistance+=newStopFuel;
            stationsUsed++;
        }
        if (maxDistance>=target) return stationsUsed;
        else return -1;
    }
};