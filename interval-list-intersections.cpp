


class Solution {

    
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int aIndex=0,bIndex=0;
        vector<vector<int>> C={};
        vector<int> tmp={};
        while (aIndex<A.size() && bIndex<B.size()) {
            vector<int> &a = A[aIndex],
                        &b = B[bIndex];
            int start = std::max(a[0],b[0]);
            int finish = std::min(a[1],b[1]);
            if ( start > a[1]  ) { aIndex++; continue; }
            if ( start > b[1]  ) { bIndex++; continue; }
            if ( finish < a[0] ) { bIndex++; continue; }
            if ( finish < b[0] ) { aIndex++; continue; }
            tmp = { start,finish };
            C.push_back(std::move(tmp));
            if (a[1]>b[1]) bIndex++;
            else aIndex++;
        }
        return C;
    }
};