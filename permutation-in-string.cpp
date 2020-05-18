class Solution {
public:
    bool checkInclusion(string s1, string s2) {
 //findAnagrams(string s, string p) {
        if (s1.size()>s2.size())
            return false;
        
        int pLetters[255]{},
            sSliceLetters[255]{};
        for (auto c : s1) {
            pLetters[c]++;
        }
        
        for (int i=0;i<s1.size();i++ ) {
            sSliceLetters[s2[i]]++;
        }
        
        for (int i=0; i<(s2.size()-s1.size()+1);i++) {
            int sliceIsAnagram=true;
            for (int j='a';j<='z';j++) {
                if (pLetters[j] != sSliceLetters[j])
                     sliceIsAnagram=false;
            }
            if (sliceIsAnagram) return true;
            sSliceLetters[s2[i]]--;
            sSliceLetters[s2[s1.size()+i]]++;
        }
        return false;
    }
};