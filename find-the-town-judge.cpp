class Solution {
public:
int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trust1(N+1, 0);
        vector<int> trust2(N+1, 0);
        for (auto tr : trust) {
            trust1[tr[0]]++;
            trust2[tr[1]]++;
        }
        for (int i = 1; i <= N; i++) {
            if (trust1[i] == 0 && trust2[i] == N - 1)
                return i ;
        }
        return -1;
    }
};