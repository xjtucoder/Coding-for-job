// leetcode triangle
// time O(n2), space O(1)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=triangle.size()-2;i>=0;--i)
            for(int j=0;j<i+1;++j)
                triangle[i][j] +=min(triangle[i+1][j], triangle[i+1][j+1]);
        return triangle[0][0];
    }
};