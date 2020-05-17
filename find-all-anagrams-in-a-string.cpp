class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        if (p.size()>s.size())
            return ret;
        
        int pLetters[255]{},
            sSliceLetters[255]{};
        for (auto c : p) {
            pLetters[c]++;
        }
        
        for (int i=0;i<p.size();i++ ) {
            sSliceLetters[s[i]]++;
        }
        
        for (int i=0; i<(s.size()-p.size()+1);i++) {
            int sliceIsAnagram=true;
            for (int j='a';j<='z';j++) {
                if (pLetters[j] != sSliceLetters[j])
                     sliceIsAnagram=false;
            }
            if (sliceIsAnagram) ret.push_back(i);
            sSliceLetters[s[i]]--;
            sSliceLetters[s[p.size()+i]]++;
        }
        return ret;
    }
};