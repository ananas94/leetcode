class Solution {
    template<typename T>
    T max(T a,T b) {
        if (a>b) return a;
        return b;
    };
    
    int64_t kadane(vector<int>& A) {
        int64_t currentSum=0;
        int64_t maxSum=A[0];
        for (int i=0; i< A.size(); i++ ) {
            currentSum+=A[i];            
            currentSum=max<int64_t>(A[i],currentSum);
            if (currentSum>maxSum) maxSum=currentSum;            
        }
        return maxSum;
    }
public:
    int maxSubarraySumCircular(vector<int>& A) {
        auto case1=kadane(A);
        int64_t sum=0;
        int64_t biggestOne=A[0];
        for (int i=0;i<A.size();i++){
            sum+=A[i];
            if (biggestOne<A[i]) biggestOne=A[i];
            A[i]=-A[i];
            
        }
        auto case2 = sum + kadane(A);
        
        auto theory = max<int64_t>(case1,case2);
        if (theory==0) return biggestOne;
        return theory;
        
    }
};