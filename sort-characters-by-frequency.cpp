class Solution {
public:
    string frequencySort(string s) {
        std::array< std::pair <char, int64_t>, 256 > toSort;        
        std::string ret="";
        
        for (auto c: s) {
            toSort[c].second++;
            toSort[c].first=c;
        }
        
        std::sort(toSort.begin(),toSort.end(), [](auto a, auto b) { return a.second>b.second; } );
        
        for (auto p: toSort) {
            while (p.second--) {
                ret+=p.first;
            }
        }
        return ret;
    }
};