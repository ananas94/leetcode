 typedef std::pair<std::pair<int,int>,std::pair<int,int>> AB;
    bool operator==(const AB& x, const AB& y) {
        return x.first.first==y.first.first &&
                x.first.second == y.first.second &&
                x.second.first == y.second.first &&
                x.second.second == y.second.second;
    }
    template<>
    struct std::hash<AB>
    {
        std::size_t operator()(AB const& x) const noexcept
        {
            return std::hash<int>{}(x.first.first)^
                   std::hash<int>{}(x.first.second) ^
                   std::hash<int>{}(x.second.first) ^
                   std::hash<int>{}(x.second.second);
        }
    };

class Solution {
    int gcd(int a, int b){
        if (a<b) return gcd(b,a);
        if (b==0) return a;
        return gcd(b, a%b);
    }
    
    std::pair<int,int> simplify(std::pair<int,int> p){
        int numerator = p.first;
        int denominator = p.second;
        int sign;
        if ( numerator >0 && denominator >0 ||
             numerator <0 && denominator <0 )
            sign =1;
        else 
            sign =-1;
        numerator = std::abs(numerator);
        denominator = std::abs(denominator);
        
        if (numerator == 0) denominator=1;
        if (denominator == 0) numerator = 1;
        int simplify=gcd(numerator,denominator);
        return std::pair(sign*numerator/simplify,denominator/simplify);
    }
    //y=ax+b
    std::pair<int,int> calcA(int x1, int y1, int x2, int y2) {
        int numerator=y1-y2;
        int denominator=x1-x2;      
        return simplify(std::pair(numerator,denominator));
    }
    std::pair<int,int> calcB(int x1, int y1, int x2, int y2) {
        int numerator=x1*y2-x2*y1;
        int denominator=x1-x2;
        return simplify(std::pair(numerator,denominator));
    }
 
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int max =0;
        for (int i=0;i<n-1;i++){
            std::unordered_map<AB,int> m;
            for (int j=i+1;j<n;j++) {
                auto a =calcA(points[i][0],points[i][1],points[j][0],points[j][1]); 
                auto b =calcB(points[i][0],points[i][1],points[j][0],points[j][1]);
                int c=++m[std::pair(a,b)];
                if (max<c) max =c;
            }
        }
        return max+1;
    }
};