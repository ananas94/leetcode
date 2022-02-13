class Solution {
public:
    int distinctEchoSubstrings(string text) {
        std::unordered_set<std::string_view> s;
        
        for (int i=0;i<text.size()-1;i++)
        {
            int l=i;
            for (int len = 1; len<=(text.size()/2);len++)
            {
                int r=l+len;
                if ((r+len)>text.size()) break;
                bool isConcatenation=true;
                for (int index=0;index<len;index++)
                    if (text[l+index]!=text[r+index]){
                        isConcatenation=false;
                        break;
                    }
                if ( isConcatenation ) {
                    s.emplace(
                        text.c_str()+l,len
                    );
                }
            }
        }
        return s.size();
    }
};