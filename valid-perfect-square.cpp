

const static  int NN = 46341;
    
 constexpr std::array<int, NN> fill_array() {
     std::array<int, NN> v{0};
     for(int i = 1; i < NN; ++i) {
         v[i] = v[i-1]+2*i-1;
     }
     return v;
 }


class Solution {
    /*
    constexpr int sqr(int x) {
        return x*x
    }
    46340
    */
    
 

    

public:
    bool isPerfectSquare(int num) {
        constexpr std::array<int, NN>  arr = fill_array();
        int mid = arr.size()/2,
            start = 0,
            end = arr.size()-1;
        while (start < end) {
            if (arr[mid]>num) {
                end = mid-1;
            }else if (arr[mid]<num) {
                start = mid+1;
            } else return true;
            mid = (end + start) / 2;
        }
        if (arr[mid]==num) return true;
        return false;
    }
};