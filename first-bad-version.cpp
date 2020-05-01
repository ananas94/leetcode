// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long start = 1;
        long long finish = n;
        while (start != finish) {
            long long mid = (start + finish) / 2;
            if (isBadVersion((int)mid)) {
                finish = mid;
            } else {
                start = mid+1;
            }
        }
        return start;
    }
};