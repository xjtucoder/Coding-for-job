/*
 * There are N children standing in a line. Each child is assigned a rating value.
 * 
 * You are giving candies to these children subjected to the following requirements:
 * 
 * Each child must have at least one candy.
 * 
 * Children with a higher rating get more candies than their neighbors.
 * 
 * What is the minimum candies you must give?
 * 
 * */
//迭代版
//时间复杂度O(n),空间复杂度O(n)
class Solution {
public:
    int candy(vector<int> &ratings) {
        
        int len=ratings.size();
        if(len==1) return 1;
         
        int sum=0;
        vector<int> v(len,1);//初始将每个孩子的糖果数都设为1
         
        //从左向右扫描，保证一个方向上分数更大的糖果更多
        for(int i=1;i<len;i++){
            if(ratings[i] > ratings[i-1])
                v[i]=v[i-1]+1;
        }
        //从右向左扫描，保证另一个方向上分数更大的糖果更多
        for(int i=len-2;i>=0;i--){
            if(ratings[i] > ratings[i+1] && v[i] <= v[i+1])
                v[i]=v[i+1]+1;
        }
         
        for(int i=0;i<len;i++){
            sum+=v[i];
        }
        return sum;
    }
};

//递归版，时间复杂度O(n),空间复杂度O(n)
class Solution
{
    public:
        int candy(vector<int>& ratings) {
            vector<int> f(ratings.size());
            int sum=0;
            for(int i=0;i<ratings.size();++i)
                sum+=solve(ratings,f,i);
            return sum;
        }
        
        int solve(vector<int>& ratings, vector<int>& f, int i){
            if(f[i]==0) {
                f[i]=1;
                if(i>0 && ratings[i] > ratings[i-1])
                    f[i]=max(f[i],solve(ratings,f,i-1)+1);
                if(i<ratings.size()-1 && ratings[i]>ratings[i+1])
                    f[i]=max(f[i],solve(ratings,f,i+1)+1);
            }
            return f[i];
        }
};
