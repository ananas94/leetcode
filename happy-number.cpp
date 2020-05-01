class Solution {
public:
    int sum(int n){
        int s=0;
        while (n>0) {
            s+=(n%10)*(n%10);
            n/=10;
        }
        return s;
    }
    bool isHappy(int n) {
        int fast=n,slow=n;
        do {
            fast=sum(fast);
            fast=sum(fast);
            slow=sum(slow);
            if (fast==1) return true;
        } while (fast!=slow);
        return false;
    }
};