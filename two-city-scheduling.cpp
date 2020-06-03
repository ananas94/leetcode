class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector <pair<int,int>> costDiffAbs(costs.size());
        for (int i=0;i<costs.size();i++) {
            costDiffAbs[i].first=abs(costs[i][0]-costs[i][1]);
            costDiffAbs[i].second=i;
        }
        sort(costDiffAbs.begin(),costDiffAbs.end(), [] (auto a, auto b) { return a.first>b.first ;  });
        int numA=0,
            numB=0;
        int64_t sum=0;
        for (int i =0; i<costs.size(); i++){
            std::cout<<"diff " << i << "   "<< costDiffAbs[i].first << endl;
            int index=costDiffAbs[i].second;
            if (numA==costs.size()/2) {
                numB++;
                sum+=costs[index][1];
            } else
            if (numB==costs.size()/2) {
                numA++;
                sum+=costs[index][0];
            } else
            if (costs[index][0] > costs[index][1]) {
                numB++;
                sum+=costs[index][1];
            } else {
                numA++;
                sum+=costs[index][0];
            }
        }
        return sum;
    }
};