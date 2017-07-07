// leetcode maximum-subarray
// time O(n), space O(1)
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int result=INT_MIN,f=0; //INT_MIN最小整数
        for(int i=0;i<n;++i)
        {
            f=max(f+A[i], A[i]);
            result=max(result, f);
        }
        return result;
    }
}; 