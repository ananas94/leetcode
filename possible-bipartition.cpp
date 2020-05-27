class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> connections(N+1);
        enum color {
            INITAL,
            RED=1,
            GREEN = -1
        };
        vector <color> colors(N+1,INITAL);
        for (auto it : dislikes) {
            int a=it[0];
            int b=it[1];
            connections[a].push_back(b);
            connections[b].push_back(a);
        }
        queue<int> queue;
        for (int i=0;i<=N;i++){
            if (colors[i]==INITAL) {
                colors[i]=RED;
                queue.push(i);
            }
            while (!queue.empty() ) {
                int index = queue.front(); queue.pop();
                for (auto otherIndex: connections[index]) {
                    if (colors[otherIndex]==INITAL) {
                        colors[otherIndex]= colors[index]==GREEN ? RED : GREEN;
                        queue.push(otherIndex);
                    } else if (colors[otherIndex]==colors[index]) 
                        return false;
                }
            }
        }
        return true;
    }
};