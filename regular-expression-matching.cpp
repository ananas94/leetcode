class Solution {
public:
    bool isMatch(string s, string p) {        
        return match(s.c_str(),p.c_str(),p.size());
    }
    bool match(const char *s,const char *p, size_t pS)
    {
        if (!p[0])
            return !s[0];
        bool first_match = s[0] && (p[0] == s[0] || p[0] == '.');
        if (pS >= 2 && p[1] == '*')
            return match(s,p+2,pS-2) || first_match && match(s+1,p,pS);
        else
            return first_match && match(s+1,p+1,pS-1);
    }
};