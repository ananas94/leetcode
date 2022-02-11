class Solution {
public:
    int numDecodings(string s) {
        s='.'+s;  //fake element to make loop work starting from index 2
        size_t ss=s.size();
        long long mod = 1000000000+7;
        std::vector<long long> single(ss), inPrev(ss);
        single[0]=1;
        inPrev[0]=0;
        
        if (s[1]=='*')
            single[1]=9;
        else if (s[1]=='0')
            single[1]=0;
        else
            single[1]=1;
        inPrev[1]=0;
        
        for (int i =2; i< ss; i++)
        {
            if (s[i]=='0')
            {
                single[i]=0;
                if (s[i-1]=='*')
                    inPrev[i]=((single[i-2]+inPrev[i-2])*2)%mod;                
                else if (s[i-1] !='1' && s[i-1]!='2')
                    return 0;
                else
                    inPrev[i]=(single[i-2]+inPrev[i-2])%mod; 
            }
            if (s[i]=='*')
            {
                single[i]=9*(single[i-1]+inPrev[i-1])%mod;
                if (s[i-1]=='1')
                    inPrev[i]=single[i-1]*9%mod;
                else if (s[i-1]=='2')
                    inPrev[i]=single[i-1]*6%mod;
                else if (s[i-1]=='*')
                    inPrev[i]=(single[i-2]+inPrev[i-2])*15%mod;
                else
                    inPrev[i]=0;
            }
            else if (s[i]=='0')
            {
                single[i]=0;
                if (s[i-1]=='*')
                    inPrev[i]=(single[i-2]+inPrev[i-2])*2%mod;
                else
                    inPrev[i]=(single[i-2]+inPrev[i-2])%mod;
            } else {
                single[i]=single[i-1]+inPrev[i-1];
                if (s[i-1]=='1') {
                       inPrev[i]=single[i-1]%mod;
                }
                else if (s[i-1]=='2' ) {
                    if ( s[i]<'7' ) {
                        inPrev[i]=single[i-1]%mod;
                    } else {
                        inPrev[i]=0;
                    }
                }   
                else if (s[i-1]=='*') {
                    if (s[i]<'7')
                        inPrev[i]=inPrev[i]=(single[i-2]+inPrev[i-2])*2%mod;
                    else 
                        inPrev[i]=(single[i-2]+inPrev[i-2])%mod;
                } else {
                    inPrev[i]=0;
                } 
            }
            
            //std::cout <<s[i]<<": " << single[i] << " " << inPrev[i]<<std::endl;
        }
        return (inPrev[ss-1]+single[ss-1])%mod;
    }
};