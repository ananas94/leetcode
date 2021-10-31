class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char map[256]{};
        char backMap[256]{};
        for (int i=0;i<s.size();i++)
        {
            if (map[s[i]]==0 && backMap[t[i]]==0){  
                map[s[i]]=t[i];
                backMap[t[i]]=s[i];
                std::cout << "map " << s[i] << " " << t[i]  <<std::endl;
            }
            else if (map[s[i]]!=t[i] || backMap[t[i]]!=s[i]) return false;
        }
        return true;
    }
};