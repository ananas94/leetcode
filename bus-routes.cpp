class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        std::unordered_map<int,std::vector<int>> paths;
        for (int i=0;i<routes.size();i++) {
            for (int j=0;j<routes[i].size();j++) {
                paths[routes[i][j]].push_back(i);
            }
        }
        std::unordered_map<int,int> distances;
        distances[source] = 0;
        std::queue<int> q;
        q.push(source);
        while (!q.empty() && distances.find(target)==distances.end())
        {
            int stop=q.front();
            q.pop();
            for (int it : paths[stop]) {
                for (auto i: routes[it])
                {
                    if (distances.find(i)==distances.end())
                    {
                        distances[i]= distances[stop]+1;
                        q.push(i);
                    }
                }
                routes[it].clear();
            }
        }
        return distances.find(target)==distances.end() ? -1 : distances[target];
    }
};