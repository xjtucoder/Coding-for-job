// leetcode maximal-rectangle
// time O(n2), space O(n)

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()) return 0;
        
        const int m=matrix.size();
        const int n=matrix[0].size();
        vector<int> H(n,0);
        vector<int> L(n,0);
        vector<int> R(n,n);
        
        int ret=0;
        for(int i=0;i<m;++i) {
            int left=0, right=n;
            // calculate L(i,j) from left to right
            for(int j=0;j<n;++j) {
                if(matrix[i][j]=='1'){
                    ++H[j];
                    L[j]=max(L[j],left); 
                }else {
                    left=j+1;
                    H[j]=0;L[j]=0;R[j]=n;
                }
            }
            
            // calculate R(i,j) from right to left
            for(int j=n-1;j>=0;--j){
                if(matrix[i][j]=='1'){
                    R[j]=min(R[j], right);
                    ret=max(ret,H[j]*(R[j]-L[j]));
                }else {
                    right=j;
                }
            }
        }
        return ret;
    }
};