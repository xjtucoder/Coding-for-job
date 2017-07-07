// leetcode
// time O(n) space O(1)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
	if(prices.empty()) return 0;
        int valley=prices[0];
        int result=0;
        for(int i=1;i<prices.size();++i)
        {
            result=max(result,prices[i]-valley);
            valley=min(valley,prices[i]);
        }
        return result;
    }
};
